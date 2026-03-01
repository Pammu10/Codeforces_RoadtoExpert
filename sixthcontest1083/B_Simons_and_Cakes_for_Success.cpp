#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    ll n;
    cin >> n;
    ll res = 1;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res *= i;     
            while (n % i == 0)
                n /= i;        
        }
    }
    if (n > 1)
        res *= n;
    cout << res << endl;
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
