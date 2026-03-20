#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 0;
    vector<bool> isRemoved(n + 1, false);
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j+=i){
            if (s[j-1] == '1') break;
            if (isRemoved[j]) continue;
            else {
                isRemoved[j] = true;
                ans += i;
            }
        }
    }
    cout << ans << "\n";
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
