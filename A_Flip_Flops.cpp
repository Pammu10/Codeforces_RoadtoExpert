#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    ll n, c, k;
    cin >> n >> c >> k;
    vector<ll> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    int ind = 0;
    while (ind < n){
        if (c < v[ind]) break;
        if (k > 0){
            ll diff = c - v[ind];
            if (k < diff){
                v[ind] += k;
                k = 0;
                c += v[ind];
            }
            else {
                k -= diff;
                v[ind] += diff;
                c += v[ind];
            }
        }
        else {
            c += v[ind];
        }
        ind++;
    }
    cout << c << "\n";

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
