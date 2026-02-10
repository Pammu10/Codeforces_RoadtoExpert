#include <bits/stdc++.h>

using namespace std;

void solve() {
    // Your problem-solving code goes here
    int n, x, y;
    cin >> n >> x >> y;
    vector<long long> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    long long total = 0;
    for (int i = 0; i < n; i++){
        total += v[i] / x;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans, v[i] + ((total - (v[i] / x)) * y));
    }
    cout << ans << endl;
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
