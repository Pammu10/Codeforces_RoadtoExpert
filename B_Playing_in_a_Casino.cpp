#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> v(m, vector<ll> (n));
    for (int j = 0; j < n; j++){
        for (int i = 0; i < m; i++){
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < m; i++){
        sort(v[i].begin(), v[i].end());
    }

    ll ans = 0;
    for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				ans -= (v[i][j] * (n - j - 1));
				ans += (v[i][j] * j);
			}
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
