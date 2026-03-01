#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n, k , x;
    cin >> n >> k >> x;
    
    if (x != 1){
        cout << "YES" << "\n";
        cout << n << "\n";
        for (int i = 0; i < n; i++){
            cout << 1 << " ";
        }
        cout << "\n";
    }
    else {
        if (k == 1 || (k == 2 && n % 2 == 1)) cout << "NO" << "\n";
        else {
            cout << "YES" << endl;
            if (n % 2 == 0) {
                cout << n / 2 << endl; 
                for (int i = 1; i <= n / 2; i++)
                    cout << 2 << " ";
                cout << endl;
            }
            else {
                cout << (n - 3) / 2 + 1 << endl;
                for (int i = 1; i <= (n - 3) / 2; i++)
                    cout << 2 << " ";
                cout << 3 << endl;
            }
        }
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
