#include <bits/stdc++.h>

using namespace std;

void solve() {
    // Your problem-solving code goes here
    long long a, b, n;
    cin >> a >> b >> n;
    long long x[n];
    for (int i = 0; i < n; i++){
        cin >> x[i];
    }
    long long maximum_sum = b;
    for (int i = 0; i < n; i++){
        maximum_sum += min(a - 1, x[i]);
    }
    cout << maximum_sum << endl;
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
