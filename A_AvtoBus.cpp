#include <bits/stdc++.h>

using namespace std;

void solve() {
    // Your problem-solving code goes here
    long long n;
    cin >> n;
    if (n < 4 || n % 2 == 1){
        cout << -1 << endl;
    }
    else {
        long long min_buses = (n + 5) / 6;
    long long max_buses = n / 4;
    cout << min_buses << " " << max_buses << endl;
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // Uncomment the next line if there are multiple test cases
    cin >> t; 
    while (t--) {
        solve();
    }

    return 0;
}
