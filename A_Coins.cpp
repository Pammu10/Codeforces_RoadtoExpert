#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    if (n % 2 == 0 || (n - k) % 2 == 0){
        cout << "YES\n";
    }
    else {
        cout << "NO\n"; 
    }
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
