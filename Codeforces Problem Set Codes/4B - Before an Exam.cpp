#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, time;
    
    while (cin >> n >> time) {
        ll min_time = 0, max_time = 0, sum_time = 0;
        ll a[35], b[35];
        vector<ll> v(n);
        
        // Reading inputs
        for (ll i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
            min_time += a[i];
            max_time += b[i];
            v[i] = a[i];
            sum_time += a[i];
        }
        
        // Check if the desired time is achievable
        if (min_time <= time && time <= max_time) {
            cout << "YES\n";
            
            // Adjust the times to match the desired total time
            for (ll i = 0; i < n && sum_time < time; ++i) {
                ll additional_time = min(b[i] - a[i], time - sum_time);
                v[i] += additional_time;
                sum_time += additional_time;
            }
            
            // Output the adjusted times
            for (ll i = 0; i < n; ++i) {
                cout << v[i] << " ";
            }
            cout << endl;
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
