#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    int target = 3 * n;
    int low = 1;
    for (int i = 0; i < n; i++){
        cout << low << " " << target << " " << target - 1 << " ";
        low++;
        target -= 2;
    }
    cout << "\n";
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
