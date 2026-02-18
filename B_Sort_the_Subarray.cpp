#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    int l = 0;
    for (; l < n; l++){
        if (a[l] != b[l]) break;
    }
    int r = n - 1;
    for (; r >= l; r--){
        if (a[r] != b[r]) break;
    }
    if (r < l) r = n - 1;
    while (l > 0 && b[l-1] <= b[l]) l -= 1;
    while (r < n - 1 && b[r+1] >= b[r]) r+= 1;
    cout << l + 1 << " " << r + 1 << endl;
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
