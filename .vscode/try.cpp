#include <iostream>
#include <vector>
#include <thread>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <chrono>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>


using namespace std;

class GameBoard {
public:
    GameBoard();
    ~GameBoard();
    void printBoard();
    bool makeMove(int column, int player_num);
    int checkWin();
    int board[6][7];

private:
    const int ROWS = 6;
    const int COLS = 7;
    const int WIN_LEN = 4;
    int countInDirection(int row, int col, int row_dir, int col_dir, int player_num);
};

GameBoard::GameBoard() {
    memset(board, 0, sizeof(board));
}

GameBoard::~GameBoard() {}

void GameBoard::printBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool GameBoard::makeMove(int column, int player_num) {
    if (column < 0 || column >= COLS) {
        return false;
    }
    int row = ROWS-1;
    while (board[row][column] != 0 && row >= 0) {
        row--;
    }
    if (row >= 0) {
        board[row][column] = player_num;
        return true;
    } else {
        return false;
    }
}

int main() {
    GameBoard game;
    int player = 1;
    while (true) {
        game.printBoard();
        int column;
        cout << "Player " << player << " enter column number: ";
        cin >> column;
        if (game.makeMove(column, player)) {
            int winner = game.checkWin();
            if (winner != 0) {
                cout << "Player " << winner << " wins!" << endl;
                break;
            }
            player = player == 1 ? 2 : 1;
        } else {
            cout << "Invalid move, try again." << endl;
        }
    }
    return 0;
}
int GameBoard::checkWin() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] != 0) {
                int player_num = board[i][j];
                // Check for horizontal win
                if (j <= COLS-WIN_LEN) {
                    bool win = true;
                    for (int k = 1; k < WIN_LEN; k++) {
                        if (board[i][j+k] != player_num) {
                            win = false;
                            break;
                        }
                    }
                    if (win) {
                        return player_num;
                    }
                }
                // Check for vertical win
                if (i <= ROWS-WIN_LEN) {
                    bool win = true;
                    for (int k = 1; k < WIN_LEN; k++) {
                        if (board[i+k][j] != player_num) {
                            win = false;
                            break;
                        }
                    }
                    if (win) {
                        return player_num;
                    }
                }
                // Check for diagonal win (down-right)
                if (i <= ROWS-WIN_LEN && j <= COLS-WIN_LEN) {
                    bool win = true;
                    for (int k = 1; k < WIN_LEN; k++) {
                        if (board[i+k][j+k] != player_num) {
                            win = false;
                            break;
                        }
                    }
                    if (win) {
                        return player_num;
                    }
                }
                // Check for diagonal win (down-left)
                if (i <= ROWS-WIN_LEN && j >= WIN_LEN-1) {
                    bool win = true;
                    for (int k = 1; k < WIN_LEN; k++) {
                        if (board[i+k][j-k] != player_num) {
                            win = false;
                            break;
                        }
                    }
                    if (win) {
                        return player_num;
                    }
                }
            }
        }
    }
    return 0;
}


