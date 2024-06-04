#include <bits/stdc++.h>
using namespace std;

const int N = 1000003;
char s[N];
int cnt[N], len[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s + 1;
    stack<int> st;
    int n = strlen(s + 1);
    cnt[0] = 1;
    
    for (int i = 1; i <= n; ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else if (!st.empty()) {
            len[i] = i - st.top() + len[st.top() - 1] + 1;
            ++cnt[len[i]];
            st.pop();
        }
    }
    
    for (int i = n; i >= 0; --i) {
        if (cnt[i]) {
            cout << i << ' ' << cnt[i];
            break;
        }
    }
    
    return 0;
}
