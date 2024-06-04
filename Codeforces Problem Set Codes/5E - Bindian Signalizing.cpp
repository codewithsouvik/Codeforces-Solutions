#include<bits/stdc++.h>
using namespace std;
typedef long long llong;

int main() {
    ios::sync_with_stdio(false); // Disable synchronization with C-style I/O
    cin.tie(nullptr); // Untie cin from cout for faster input

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    rotate(v.begin(), max_element(v.begin(), v.end()), v.end());
    v.push_back(v[0]);

    vector<int> left(n + 1, -1);
    vector<int> right(n + 1, n + 1);
    vector<int> same(n + 1, 0);

    stack<int> s;
    s.push(0);

    for (int i = 1; i < n; ++i) {
        while (!s.empty() && v[s.top()] <= v[i]) {
            if (v[s.top()] == v[i])
                same[i] = same[s.top()] + 1;
            s.pop();
        }
        if (!s.empty())
            left[i] = s.top();
        s.push(i);
    }

    while (!s.empty())
        s.pop();

    s.push(n);
    right[n] = n;

    for (int i = n - 1; i >= 1; --i) {
        while (!s.empty() && v[s.top()] <= v[i])
            s.pop();
        if (!s.empty())
            right[i] = s.top();
        s.push(i);
    }

    llong ans = 0;
    for (int i = 1; i < n; ++i) {
        if (left[i] != -1)
            ans++;
        if (right[i] != n + 1)
            ans++;
        if (left[i] == 0 && right[i] == n)
            ans--;
        ans += same[i];
    }

    cout << ans << endl;
    return 0;
}
