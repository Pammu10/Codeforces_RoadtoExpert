#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<ll> prefix(n);
    prefix[0] = v[0];
    for (int i = 1; i < n; i++){
        prefix[i] = prefix[i-1] + v[i];
    }
    ll ans = 0;
    for (ll k = 1; k <= n; k++){
        if (n % k) continue;
        ll start = k - 1;
        ll res = 0;
        ll maxi = prefix[start];
        ll mini = prefix[start];
        for (ll i = start + k; i < n; i+= k){
            ll cur = prefix[i] - prefix[i - k];
            maxi = max(maxi, cur);
            mini = min(mini, cur);
        }
        ans = max(ans, maxi - mini);
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
