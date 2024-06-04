#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // To ignore the newline character after the integer input

    for (int _ = 0; _ < n; _++) {
        string ch;
        getline(cin, ch);
        int m = ch.length();
        int C = 1;
        
        while (C < m && isdigit(ch[C])) {
            C++;
        }

        if (1 < C && C < m) {
            int col = 0;
            for (int i = C + 1; i < m; i++) {
                col = col * 10 + (ch[i] - '0');
            }

            int pow = 26;
            while (col > pow) {
                col -= pow;
                pow *= 26;
            }

            col -= 1;
            while (pow != 1) {
                pow /= 26;
                cout << static_cast<char>(col / pow + 'A');
                col %= pow;
            }

            ch = ch.substr(0, C);
            cout << ch.substr(1) << endl;
        } else {
            int col = 0;
            int val = 0;
            int pow = 1;
            int i = 0;
            while (isalpha(ch[i])) {
                col += pow;
                pow *= 26;
                val = val * 26 + ch[i] - 'A';
                i++;
            }
            col += val;
            cout << "R" << ch.substr(i) << "C" << col << endl;
        }
    }

    return 0;
}
