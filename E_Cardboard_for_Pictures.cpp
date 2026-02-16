#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    ll n, c;
    cin >> n >> c;
    vector<ll> s(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    ll high = 1e9;
    ll low = 1;
    ll ans = -1;
    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        ll total = 0;
        for (ll i = 0; i < s.size(); i++)
        {
            total += (s[i] + 2 * mid) * (s[i] + 2 * mid);
            if (total > c)
                break;
        }
        if (total <= c)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << endl;
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
