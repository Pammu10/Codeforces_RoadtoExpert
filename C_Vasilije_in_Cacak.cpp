#include <bits/stdc++.h>

using namespace std;

void solve() {
    // Your problem-solving code goes here
    long long n, k, x;
    cin >> n >> k >> x;
    long long minSum = (k*(k+1)) / 2;
    long long maxSum = (n*(n+1)) / 2 - ((n-k)*(n-k+1)) / 2;
    if (x <= maxSum && x >= minSum) cout << "YES" << endl;
    else cout << "NO" << endl;
    // Process input and produce output
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
