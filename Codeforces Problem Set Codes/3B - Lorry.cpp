#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main() {
    int n, m;
    cin >> n >> m;

    vector<PII> a, b;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (x == 1)
            a.push_back({y, i + 1});
        else
            b.push_back({y, i + 1});
    }

    sort(a.begin(), a.end(), greater<PII>());
    sort(b.begin(), b.end(), greater<PII>());

    int n1 = a.size(), n2 = b.size();
    vector<LL> prefix_sum_a(n1 + 1), prefix_sum_b(n2 + 1);

    for (int i = 0; i < n1; i++)
        prefix_sum_a[i + 1] = prefix_sum_a[i] + a[i].first;

    for (int i = 0; i < n2; i++)
        prefix_sum_b[i + 1] = prefix_sum_b[i] + b[i].first;

    int ans = 0, x = 0, y = 0;

    for (int i = 0, j = n2; i <= n1; i++) {
        while (j > 0 && i + 2 * j > m)
            j--;

        if (i + 2 * j <= m && prefix_sum_a[i] + prefix_sum_b[j] > ans) {
            ans = prefix_sum_a[i] + prefix_sum_b[j];
            x = i;
            y = j;
        }
    }

    cout << ans << endl;

    for (int i = 0; i < x; i++)
        cout << a[i].second << " ";

    for (int i = 0; i < y; i++)
        cout << b[i].second << " ";

    cout << endl;

    return 0;
}
