#include <bits/stdc++.h>
using namespace std;

bool checkWin(const string s[3], char c) {
    for (int i = 0; i < 3; ++i) {
        if (s[i][0] == c && s[i][1] == c && s[i][2] == c) return true; // Check rows
        if (s[0][i] == c && s[1][i] == c && s[2][i] == c) return true; // Check columns
    }
    if (s[0][0] == c && s[1][1] == c && s[2][2] == c) return true; // Check main diagonal
    if (s[0][2] == c && s[1][1] == c && s[2][0] == c) return true; // Check anti-diagonal
    return false;
}

int main() {
    string s[3];
    int x = 0, o = 0;

    // Input the game board
    for (int i = 0; i < 3; ++i) {
        cin >> s[i];
        for (int j = 0; j < 3; ++j) {
            if (s[i][j] == 'X') ++x;
            else if (s[i][j] == '0') ++o;
        }
    }

    // Check for illegal state
    if (x - o < 0 || x - o > 1 || (checkWin(s, 'X') && checkWin(s, '0')) || (checkWin(s, 'X') && x == o) ||
        (checkWin(s, '0') && x > o)) {
        cout << "illegal" << endl;
    } else if (checkWin(s, 'X')) {
        cout << "the first player won" << endl;
    } else if (checkWin(s, '0')) {
        cout << "the second player won" << endl;
    } else if (x + o == 9) {
        cout << "draw" << endl;
    } else if (x == o) {
        cout << "first" << endl;
    } else {
        cout << "second" << endl;
    }

    return 0;
}
