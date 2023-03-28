#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#ifndef MSG_CONFIRM
#define MSG_CONFIRM 0x800
#endif

int main() {
    int sockfd;
    char buffer[1024] = {0};
    struct sockaddr_in server_addr, client_addr;
    int client_addr_len = sizeof(client_addr);

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        std::cerr << "Socket creation failed" << std::endl;
        return 1;
    }

    // Bind the socket to a port and address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Socket binding failed" << std::endl;
        return 1;
    }

    // Receive message from client and send a response
    int n;
    while (true) {
        // Receive the message in chunks and concatenate them
        std::string message;
        while (true) {
            n = recvfrom(sockfd, buffer, 1024, MSG_WAITALL, (struct sockaddr *) &client_addr, (socklen_t *) &client_addr_len);
            if (n < 0) {
                break;
            }
            message.append(buffer, n);
            if (n < 1024) {
                break;
            }
        }

        std::cout << "Received message from client: " << message << std::endl;

       // Send a response to the client
        std::string response;
        std::cout << "Type a response to send to the client: " << std::endl;
        std::getline(std::cin, response);
        sendto(sockfd, response.c_str(), response.length(), MSG_CONFIRM, (const struct sockaddr *) &client_addr, client_addr_len);
    std::cout << "Response sent to client: " << response << std::endl;

    }

    close(sockfd);
    return 0;
}
