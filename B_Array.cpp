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
    vector<int> ans(n, 0);
    for (int i = 0; i < n - 1; i++){
        int cntg = 0;
        int cntl = 0;
        int dup = 0;
        for (int j = i + 1; j < n; j++){
            if (v[j] > v[i]) cntg++; 
            else if (v[i] > v[j]) cntl++;
            else dup++;
        }
        ans[i] = n - 1 - i - dup - min(cntg, cntl);
    }

    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
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
