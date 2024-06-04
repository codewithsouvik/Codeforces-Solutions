#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int l = 0, r = n - 1;
    int sum_l = 0, sum_r = 0;
    int cnt_l = 0, cnt_r = 0;

    while (l <= r)
    {
        if (sum_l == sum_r)
        {
            sum_l += v[l];
            l++;
            cnt_l++;
        }
        else if (sum_l > sum_r)
        {
            sum_r += v[r];
            r--;
            cnt_r++;
        }
        else
        {
            sum_l += v[l];
            l++;
            cnt_l++;
        }
    }

    cout << cnt_l << " " << cnt_r << '\n';

    return 0;
}
