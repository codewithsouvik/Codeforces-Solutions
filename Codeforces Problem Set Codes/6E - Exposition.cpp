#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAXN = 1e5 + 5;
int n, k;
int h[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int l = 0, r = 0;
    deque<int> qmin, qmax;
    qmin.push_back(0);
    qmax.push_back(0);
    int best = 0;

    while (r < n) {
        int diff = h[qmax.front()] - h[qmin.front()];
        if (diff <= k) {
            best = max(best, r - l + 1);
            r++;
            if (r < n) {
                while (!qmax.empty() && h[qmax.back()] <= h[r]) {
                    qmax.pop_back();
                }
                while (!qmin.empty() && h[qmin.back()] >= h[r]) {
                    qmin.pop_back();
                }
                qmax.push_back(r);
                qmin.push_back(r);
            }
        } else {
            if (qmax.front() == l) qmax.pop_front();
            if (qmin.front() == l) qmin.pop_front();
            l++;
        }
    }

    l = 0, r = 0;
    qmin.clear();
    qmax.clear();
    qmin.push_back(0);
    qmax.push_back(0);

    while (r < best - 1) {
        r++;
        while (!qmax.empty() && h[qmax.back()] <= h[r]) {
            qmax.pop_back();
        }
        while (!qmin.empty() && h[qmin.back()] >= h[r]) {
            qmin.pop_back();
        }
        qmax.push_back(r);
        qmin.push_back(r);
    }

    vector<int> starts;
    while (r < n) {
        if (h[qmax.front()] - h[qmin.front()] <= k) {
            starts.push_back(l);
        }
        if (qmax.front() == l) qmax.pop_front();
        if (qmin.front() == l) qmin.pop_front();
        l++;
        r++;
        if (r < n) {
            while (!qmax.empty() && h[qmax.back()] <= h[r]) {
                qmax.pop_back();
            }
            while (!qmin.empty() && h[qmin.back()] >= h[r]) {
                qmin.pop_back();
            }
            qmax.push_back(r);
            qmin.push_back(r);
        }
    }

    cout << best << " " << starts.size() << endl;
    for (int x : starts) {
        cout << x + 1 << " " << (x + best) << endl;
    }

    return 0;
}
