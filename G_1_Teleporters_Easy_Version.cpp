#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    for (int i = 0; i < n; i++){
        v[i] += i + 1;
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    int i = 0;
    while (c > 0 && i < n){
        if (c - v[i] >= 0) cnt++;
        c -= v[i++];
    }
    cout << cnt << "\n";
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
