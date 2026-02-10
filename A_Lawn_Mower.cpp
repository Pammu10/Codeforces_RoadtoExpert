#include <bits/stdc++.h>

using namespace std;

void solve() {
    // Your problem-solving code goes here
    int n, w;
    cin >> n >> w;
    int quo = n / w;
    int rem = n - quo;
    cout << rem << endl;
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
