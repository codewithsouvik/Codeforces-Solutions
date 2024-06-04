#include <iostream>
using namespace std;

int main() {
    unsigned long long n, m, a;
    cin >> n >> m >> a;
    
    // Calculate the number of tiles required along each dimension without using ceil
    unsigned long long tilesAlongM = (m + a - 1) / a;
    unsigned long long tilesAlongN = (n + a - 1) / a;
    
    // Calculate the total number of tiles
    unsigned long long totalTiles = tilesAlongM * tilesAlongN;
    
    // Print the result
    cout << totalTiles << endl;

    return 0;
}
