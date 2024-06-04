#include <bits/stdc++.h>

int main() {
    using namespace std;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> lines;
    string line;
    auto maxLen {0};
    
    while (getline(cin, line)) {
        lines.push_back(line);
        if (line.length() > maxLen) {
            maxLen = line.length();
        }
    }
    
    string border(maxLen + 2, '*');
    string result;
    result.resize((lines.size() + 2) * (maxLen + 2) + 4);
    result = "";
    result += border + "\n";

    auto leftAlign {true};
    string padLeft(maxLen, ' '), padRight(maxLen, ' ');
    
    for (const auto& ln : lines) {
        int padLeftSize = 0, padRightSize = 0;
        padLeftSize = padRightSize = (maxLen - ln.length()) / 2;
        
        if ((maxLen - ln.length()) % 2 != 0) {
            if (leftAlign) {
                padRightSize += 1;
            } else {
                padLeftSize += 1;
            }
            leftAlign = !leftAlign;
        }
        
        padLeft.resize(padLeftSize, ' ');
        padRight.resize(padRightSize, ' ');
        
        result += "*";
        result += padLeft;
        result += ln;
        result += padRight;
        result += "*\n";
    }

    result += border;

    cout << result;
    return 0;
}
