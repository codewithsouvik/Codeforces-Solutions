#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int dx = t[0] - s[0];
    int dy = t[1] - s[1];

    int steps = max(abs(dx), abs(dy));
    cout << steps << endl;

    while (dx || dy) {
        if (dx > 0) {
            cout << "R";
            dx--;
        } else if (dx < 0) {
            cout << "L";
            dx++;
        }

        if (dy > 0) {
            cout << "U";
            dy--;
        } else if (dy < 0) {
            cout << "D";
            dy++;
        }

        cout << endl;
    }

    return 0;
}
