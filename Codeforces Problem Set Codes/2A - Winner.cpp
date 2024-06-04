#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<pair<string, int>> entries(n);
    unordered_map<string, int> scores;
    
    // Reading input and calculating total scores
    for (int i = 0; i < n; ++i) {
        cin >> entries[i].first >> entries[i].second;
        scores[entries[i].first] += entries[i].second;
    }
    
    // Find the maximum score
    int maximum = INT_MIN;
    for (const auto& entry : scores) {
        if (entry.second > maximum) {
            maximum = entry.second;
        }
    }
    
    // Finding all potential winners
    unordered_set<string> potential_winners;
    for (const auto& entry : scores) {
        if (entry.second == maximum) {
            potential_winners.insert(entry.first);
        }
    }
    
    // Clearing scores map to reuse it for tracking cumulative scores
    scores.clear();
    
    // Determine the first player to reach or exceed the maximum score
    for (const auto& entry : entries) {
        scores[entry.first] += entry.second;
        if (potential_winners.count(entry.first) && scores[entry.first] >= maximum) {
            cout << entry.first << "\n";
            return 0;
        }
    }
    
    return 0;
}
