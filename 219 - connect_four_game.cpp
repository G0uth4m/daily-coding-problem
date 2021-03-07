/*
This problem was asked by Salesforce.

Connect 4 is a game where opponents take turns dropping red or black discs into a 7 x 6 vertically suspended grid. 
The game ends either when one player creates a line of four consecutive discs of their color 
(horizontally, vertically, or diagonally), or when there are no more spots left in the grid.

Design and implement Connect 4.
*/

#include <iostream>
#include <vector>
using namespace std;

enum Disc {
    red, black, empty
};

class ConnectFour {
private:
    vector<vector<Disc>> grid;
    vector<int> colsDp;
    int numDiscsPlaced;
    pair<int, int> prevMove;

    void __print_grid() {
        cout << "  ";
        for (int i=0; i<6; i++) {
            cout << i << " ";
        }
        cout << "\n";
        int rowNum = 0;
        for (vector<Disc>& i : grid) {
            cout << rowNum++ << " ";
            for (Disc j : i) {
                switch (j) {
                    case red:
                    cout << "R" << " ";
                    break;

                    case black:
                    cout << "B" << " ";
                    break;

                    case empty:
                    cout << " " << " ";
                    break;
                }
            }
            cout << "\n";
        }
        cout << "\n";
    }

    bool __check_row(int row, int col) {
        int res = 0;
        pair<int, int> temp = {row, col};
        Disc disc = grid[row][col];
        while (col >= 0 && grid[row][col] == disc) {
            res++;
            col--;
        }
        row = temp.first;
        col = temp.second + 1;
        while (col < 6 && grid[row][col] == disc) {
            res++;
            col++;
        }
        return res == 4;
    }

    bool __check_col(int row, int col) {
        int res = 0;
        pair<int, int> temp = {row, col};
        Disc disc = grid[row][col];
        while (row >= 0 && grid[row][col] == disc) {
            res++;
            row--;
        }
        row = temp.first + 1;
        col = temp.second;
        while (row < 7 && grid[row][col] == disc) {
            res++;
            row++;
        }
        return res == 4;
    }

    bool __check_neg_diagnol(int row, int col) {
        int res = 0;
        pair<int, int> temp = {row, col};
        Disc disc = grid[row][col];
        while (row >= 0 && col >= 0 && grid[row][col] == disc) {
            res++;
            row--;
            col--;
        }

        row = temp.first;
        col = temp.second;
        while (row < 7 && col < 6 && grid[row][col] == disc) {
            res++;
            row++;
            col++;
        }
        return res - 1 == 4;
    }

    bool __check_pos_diagnol(int row, int col) {
        int res = 0;
        pair<int, int> temp = {row, col};
        Disc disc = grid[row][col];
        while (row < 7 && col >= 0 && grid[row][col] == disc) {
            res++;
            row++;
            col--;
        }

        row = temp.first;
        col = temp.second;
        while (row >= 0 && col < 6 && grid[row][col] == disc) {
            res++;
            row--;
            col++;
        }
        return res - 1 == 4;
    }

    void __clear_screen() {
        cout << "\033[2J\033[1;1H";
    }

public:
    ConnectFour() {
        grid.assign(7, vector<Disc>(6, empty));
        colsDp.assign(6, 6);
        numDiscsPlaced = 0;
        prevMove = {-1, -1};
    }

    void dropDisc(Disc disc, int col) {
        if (colsDp[col] == -1) {
            throw "[-] Column is completely filled. Try again...";
        }
        int row = colsDp[col]--;
        grid[row][col] = disc;
        prevMove = {row, col};
        numDiscsPlaced++;
    }

    bool isDrawn() {
        return numDiscsPlaced == 42;
    }

    bool isWon() {
        int row = prevMove.first;
        int col = prevMove.second;
        if (row == -1) {
            return false;
        }
        return __check_row(row, col)
            || __check_col(row, col)
            || __check_neg_diagnol(row, col)
            || __check_pos_diagnol(row, col);
    }

    bool gameOver() {
        return isWon() || isDrawn();
    }

    void play() {
        bool isRedTurn = true;
        while (!gameOver()) {
            __print_grid();
            int col;
            if (isRedTurn) {
                cout << "[*] Red's turn\n";
                cout << "[*] column: ";
                cin >> col;
                try {
                    dropDisc(red, col);
                } catch (const char* msg) {
                    __clear_screen();
                    cout << msg << "\n\n";
                    continue;
                }
                isRedTurn = false;
            } else {
                cout << "[*] Black's turn\n";
                cout << "[*] column: ";
                cin >> col;
                try {
                    dropDisc(black, col);
                } catch (const char* msg) {
                    __clear_screen();
                    cout << msg << "\n\n";
                    continue;
                }
                isRedTurn = true;
            }
            cout << endl;
            __clear_screen();
        }
        cout << "[+] Game Over!\n\n";
        __print_grid();
    }
};

int main() {
    ConnectFour connectFour;
    connectFour.play();
}
