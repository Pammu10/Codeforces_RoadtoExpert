#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve() {
    int n;
    long long x, y;
    cin >> n >> x >> y;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long beautiful_pairs = 0;
    
    // Map to store the frequency of the pairs: { a_i % x, a_i % y }
    map<pair<long long, long long>, int> freq;

    for (int i = 0; i < n; ++i) {
        long long mod_x = a[i] % x;
        long long mod_y = a[i] % y;

        // Calculate what we need from a previous element to form a valid pair
        long long needed_x = (x - mod_x) % x;
        long long needed_y = mod_y;

        // If we have seen this required combination before, add its frequency to our answer
        if (freq.count({needed_x, needed_y})) {
            beautiful_pairs += freq[{needed_x, needed_y}];
        }

        // Add the current element's modulos to our map for future elements to pair with
        freq[{mod_x, mod_y}]++;
    }

    cout << beautiful_pairs << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}