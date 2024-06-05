#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long a, b, c;
  cin >> a >> b >> c;
  long long ax = 1, bx = 0, ay = 0, by = 1;
  for (; b != 0; swap(a, b), swap(ax, bx), swap(ay, by)) {
    long long t = a / b;
    a -= b * t;
    ax -= bx * t;
    ay -= by * t;
  }
  const long long limit = (long long) 5e18;
  if (c % a != 0) {
    cout << -1 << '\n';
  } else {
    ax *= -c / a;
    ay *= -c / a;
    if (abs(ax) <= limit && abs(ay) <= limit) {
      cout << ax << ' ' << ay << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
  return 0;
}
