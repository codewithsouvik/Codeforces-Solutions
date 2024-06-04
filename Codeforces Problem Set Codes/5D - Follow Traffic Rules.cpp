#include <bits/stdc++.h>

#define ll long long
using namespace std;

double acc, maxVel, dist, slowDist, limitVel;

double calcTime1(double dist) {
    double time = (dist - (maxVel * maxVel - limitVel * limitVel) / (2 * acc)) / maxVel + (maxVel - limitVel) / acc;
    if (time - (maxVel - limitVel) / acc >= 0) {
        return time;
    }
    return (-limitVel + sqrt(limitVel * limitVel + 2 * dist * acc)) / acc;
}

double calcTime2(double dist) {
    double t0 = limitVel / acc;
    double remDist = dist - acc * t0 * t0 / 2;
    if (remDist <= 0) {
        t0 = sqrt(2 * dist / acc);
        limitVel = acc * t0;
        return t0;
    }
    t0 = maxVel / acc;
    remDist = dist - acc * t0 * t0 / 2;
    double time = (remDist - (maxVel * maxVel - limitVel * limitVel) / (2 * acc)) / maxVel + (maxVel - limitVel) / acc;
    if (remDist >= 0 && time - (maxVel - limitVel) / acc >= 0) {
        return time + t0;
    }
    double t1 = sqrt(dist / acc + limitVel * limitVel / (2 * acc * acc));
    time = 2 * t1 - limitVel / acc;
    return time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> acc >> maxVel >> dist >> slowDist >> limitVel;
    limitVel = min(limitVel, maxVel);
    cout << fixed << setprecision(8);
    double time1 = calcTime2(slowDist);
    double time2 = calcTime1(dist - slowDist);
    cout << time1 + time2 << endl;
}
