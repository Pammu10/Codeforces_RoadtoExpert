#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; i++){
        cin >> x[i];
    }
    for (int i = 0; i < n; i++){
        cin >> y[i];
    }
    vector<int> diff;
    for (int i = 0; i < n; i++){
        diff.push_back(y[i] - x[i]);
    }
    sort(diff.begin(), diff.end());
    int r = n - 1;
    int l = 0;
    ll cnt = 0;
    int diffNum = 0;
    while (r - l >= 1){
        diffNum = diff[r] + diff[l];
        if (diffNum >= 0){
            l++;
            r--;
            cnt++;
            diffNum = 0;
        }
        else {
            l++;
            
        }
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
