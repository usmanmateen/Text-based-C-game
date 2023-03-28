#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sstream>

#define PORT 8080
#ifndef MSG_CONFIRM
#define MSG_CONFIRM 0x800
#endif

int main() {
    int sockfd;
    char buffer[4096] = {0};
    struct sockaddr_in server_addr;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        std::cerr << "Socket creation failed" << std::endl;
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address or address not supported" << std::endl;
        return 1;
    }

    // Send and receive messages in a loop
    std::string message;
    std::cout << "Type a message to send or 'exit' to quit:" << std::endl;
    while (true) {
        std::getline(std::cin, message);
        if (message == "exit") {
            break;
        }

        // Send the message in chunks
        std::stringstream ss(message);
        std::string chunk;
        while (std::getline(ss, chunk, '|')) {
            sendto(sockfd, chunk.c_str(), chunk.length(), MSG_CONFIRM, (const struct sockaddr *) &server_addr, sizeof(server_addr));
        }

        std::cout << "sent: " << message << std::endl;

        // Receive the response
        int n;
        socklen_t len = sizeof(server_addr);
        n = recvfrom(sockfd, (char *) buffer, 4096, MSG_WAITALL, (struct sockaddr *) &server_addr, &len);
        buffer[n] = '\0';
        std::cout << "server: " << buffer << std::endl;

    }

    close(sockfd);
    return 0;
}
