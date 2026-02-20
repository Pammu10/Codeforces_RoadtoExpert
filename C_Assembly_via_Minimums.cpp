#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    ll m = (n*(n-1)) / 2;
    vector<ll> v(m);
    for (int i = 0; i < m; i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    ll x = n - 1;
    ll i = 0;
    while (x > 0){
        cout << v[i] << " ";
        i += x;
        x--;
    }
    cout << "1000000000\n";
    
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
