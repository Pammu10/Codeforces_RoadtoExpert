#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    int n, k, p, m;
    cin >> n >> k >> p >> m;

    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll target_cost = v[p - 1];

    ll c1 = target_cost;
    if (p > k)
    {
        vector<ll> prefix(v.begin(), v.begin() + p - 1);
        sort(prefix.begin(), prefix.end());
        for (int i = 0; i < p - k; i++)
        {
            c1 += prefix[i];
        }
    }
    ll cc = target_cost;
    if (n > k)
    {
        vector<ll> others;
        for (int i = 0; i < n; i++)
        {
            if (i != p - 1)
                others.push_back(v[i]);
        }
        sort(others.begin(), others.end());
        for (int i = 0; i < n - k; i++)
        {
            cc += others[i];
        }
    }
    if (m < c1)
    {
        cout << 0 << "\n";
    }
    else
    {
        ll ans = 1 + (m - c1) / cc;
        cout << ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}