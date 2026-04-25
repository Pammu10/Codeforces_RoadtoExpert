#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    string ans = "No";
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        if (a == 100) {ans = "Yes";}
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
