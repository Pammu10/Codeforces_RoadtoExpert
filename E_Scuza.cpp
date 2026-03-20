#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<ll> prefix(n);
    vector<ll> pmax(n);
    prefix[0] = v[0];
    pmax[0] = v[0];
    for (ll i = 1; i < n; i++){
        pmax[i] = max(pmax[i-1], v[i]);
        prefix[i] = prefix[i-1] + v[i];
    }
    vector<ll> ans;
    for (ll i = 0; i < q; i++){
        
        ll query;
        cin >> query;
        int low = 0;
        int high = n -1;
        int ind = -1;
        while (low <= high){
            int mid = (high + low) / 2;
            if (pmax[mid] <= query){
                ind = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        if (ind == -1) cout << 0 << " ";
        else cout << prefix[ind] << " ";
        
    }cout << "\n";

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
