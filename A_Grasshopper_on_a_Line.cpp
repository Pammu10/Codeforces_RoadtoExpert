#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    long long x, k;
        cin >> x >> k;
        if (x % k != 0){
            cout << 1 << "\n";
            cout << x << "\n";
        }
        else {
            cout << 2 << "\n";
            cout << 1 << " ";
            cout << x - 1 << "\n";
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
