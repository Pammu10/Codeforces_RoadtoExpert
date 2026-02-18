#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++){
       cin >> a[i]; 
    }
    long long ans = 0;
    for (int i = 0; i < n; i++){
        ans = __gcd(ans, abs(a[i] - a[n - i -1]));
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
