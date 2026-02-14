#include <bits/stdc++.h>

using namespace std;

void solve() {
    // Your problem-solving code goes here
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int j = 0;
    int i = 0;
    int count = 0;
    for (; j < k; j++){
        if (s[j] == 'W') count++;
    }

    int minChanges = count;
    for (; j < n; j++){
        if (s[j] == 'W') count++;
        
        if (s[j - k] == 'W') count--;
        minChanges = min(minChanges, count);
    }
    cout << minChanges << endl;
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
