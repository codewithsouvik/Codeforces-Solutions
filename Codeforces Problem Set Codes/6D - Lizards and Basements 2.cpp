#include <bits/stdc++.h>
using namespace std;

const int MAXN = 15;
const int INF = INT_MAX;
int n, a, b, t;
int h[MAXN];
int best_operations = INF;
vector<int> best_count(MAXN, 0), cnt(MAXN, 0);

void search(int idx, int cur) {
    if (cur >= best_operations) return; // early pruning
    if (idx == n - 1) {
        if (cur < best_operations) {
            best_operations = cur;
            best_count = cnt;
            best_count[n - 2] += t; // remember to add the initial operations
        }
        return;
    }
    int x = (h[idx - 1] >= 0) ? (h[idx - 1] / b + 1) : 0;
    while (cur + x < best_operations) {
        h[idx - 1] -= x * b;
        h[idx] -= x * a;
        h[idx + 1] -= x * b;
        cnt[idx] = x;
        search(idx + 1, cur + x);
        h[idx - 1] += x * b;
        h[idx] += x * a;
        h[idx + 1] += x * b;
        x++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    t = h[n - 1] / b + 1;
    h[n - 1] -= t * b;
    h[n - 2] -= t * a;
    h[n - 3] -= t * b;

    search(1, t);

    cout << best_operations << endl;

    vector<string> s;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < best_count[i]; ++j) {
            s.push_back(to_string(i + 1));
        }
    }
    cout << accumulate(s.begin(), s.end(), string(), [](string a, string b) { return a.empty() ? b : a + " " + b; }) << endl;

    return 0;
}
