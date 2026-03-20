#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll count(ll n, ll m, ll rb, vector<vector<ll>> &dp, ll mod)
{
    if (n == 0 && m == 0)
    {
        return 1;
    }
    if (dp[n][m] != -1)
    {
        return dp[n][m];
    }
    dp[n][m] = 0;
    ll left = -1;
    if (m > 0)
        left = count(n, m - 1, rb, dp, mod);
    ll right = -1;
    if (m < rb)
        right = count(n, m + 1, rb, dp, mod);
    ll top = -1;
    if (n > 0)
        top = count(n - 1, m, rb, dp, mod);
    return dp[n][m] = (1 + max(left, max(right, top))) % mod;
}

void solve()
{
    ll n, m, mod;
    cin >> n >> m >> mod;
    vector<vector<ll>> dp(n, vector<ll>(m, -1));
    ll ans = count(n - 1, m - 1, m - 1, dp, mod);
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
