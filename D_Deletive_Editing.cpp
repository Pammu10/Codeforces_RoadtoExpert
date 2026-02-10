#include <bits/stdc++.h>

using namespace std;

void solve() {
    // Your problem-solving code goes here
    string s, t;
    cin >> s >> t;
    int m = s.size();
    int n = t.size();
    vector<int> freq_t(26, 0);
    for (int i = 0; i < n; i++){
        freq_t[t[i] - 'A']++;
    }
    for (int i = m - 1; i >= 0; i--){
        if (freq_t[s[i] - 'A'] > 0){
            freq_t[s[i] - 'A']--;
        }
        else {
            s[i] = '.';
        }
    }
    string finalstr;
    for (int i = 0; i < m; i++){
        if (s[i] != '.'){
            finalstr += s[i];
        }
    }
    if (finalstr == t){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
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
