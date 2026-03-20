#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 1;
    for (; i < n; i++){
        if (s[i] == 'L'){
            break;
        }
    }
    cout << i + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) {
        solve();
    }

    return 0;
}
