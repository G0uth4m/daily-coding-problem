/*
Given a 2-D matrix representing an image, a location of a pixel in the screen and a color C, 
replace the color of the given pixel and all adjacent same colored pixels with C.

For example, given the following matrix, and location pixel of (2, 2), and 'G' for green:

B B W
W W W
W W W
B B B

Becomes

B B G
G G G
G G G
B B B

*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& screen, char new_color, char old_color, int r, int c) {
    if (r >= screen.size() || c >= screen[0].size() || new_color == old_color || screen[r][c] != old_color) {
        return;
    }
    screen[r][c] = new_color;
    dfs(screen, new_color, old_color, r + 1, c);
    dfs(screen, new_color, old_color, r, c + 1);
    dfs(screen, new_color, old_color, r - 1, c);
    dfs(screen, new_color, old_color, r, c - 1);
}

void color_fill(vector<vector<char>>& screen, char new_color, pair<int, int> pixel) {
    dfs(screen, new_color, screen[pixel.first][pixel.second], pixel.first, pixel.second);
}

void print(vector<vector<char>>& A) {
    for (vector<char>& i : A) {
        for (char j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<char>> screen = {
        {'B', 'B', 'W'},
        {'W', 'W', 'W'},
        {'W', 'W', 'W'},
        {'B', 'B', 'B'}
    };
    color_fill(screen, 'G', {2, 2});
    print(screen);
}
