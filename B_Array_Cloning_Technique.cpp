#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll cnt = 1;
    ll maxC = 1;
    ll curVal = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] == curVal)
        {
            cnt++;
            maxC = max(maxC, cnt);
        }
        else
        {
            curVal = v[i];
            maxC = max(maxC, cnt);
            cnt = 1;
        }
    }
    maxC = max(maxC, cnt);
    if (maxC == n)
        cout << 0 << "\n";
    else
    {
        ll ans = 0;
        while (maxC < n)
        {
            ans += 1 + min(n - maxC, maxC);
            maxC *= 2;
        }
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
