#include <bits/stdc++.h>
#define MOD (ll)(1e9+7)
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    ll ans = 1;
    for (int i = 0; i < n; i++){
        ll num = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        ll count = a.size() - num;
        ans = ans * max(count - i, 0LL) % MOD;
    }
    cout << ans << endl;
    
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
