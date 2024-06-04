#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX = 5e4 + 5;
int len, cnt, q;
string str;
ll l[MAX], r[MAX], cost;
priority_queue<pair<ll, int>> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> str;
    len = str.length();
    for(int i = 0; i < len; i++) {
        if(str[i] == '?') {
            cin >> l[i] >> r[i];
            cnt--;
            pq.emplace(r[i] - l[i], i);
            cost += r[i];
            str[i] = ')';
        }else if(str[i] == '(') {
            cnt++;
        }else {
            cnt--;
        }
        if(cnt < 0) {
            if(pq.empty()) {
                cout << -1 << endl;
                return 0;
            }
            int j = pq.top().second;
            pq.pop();
            cost += l[j] - r[j];
            cnt += 2;
            str[j] = '(';
        }
    }
    if(cnt != 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << cost << endl << str << endl;
}
