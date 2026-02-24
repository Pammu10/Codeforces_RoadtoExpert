#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    int n, h, k;
    cin >> n >> h >> k;
    vector<ll> v(n);
    ll maxVal = 0;
    ll maxPos = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (maxVal <= v[i])
        {
            maxVal = v[i];
            maxPos = i;
        }
    }
    vector<ll> pre(n);
    pre[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + v[i];
    }
    ll time = 0;
    ll sumDamage = accumulate(v.begin(), v.end(), 0LL);
    ll cycles = (h - 1) / sumDamage;
    time += cycles * (n + k);
    ll rem_health = h - cycles * sumDamage;
    ll mn = LLONG_MAX;
    ll pp = maxPos;
    for (int i = 0; i < maxPos; i++)
    {
        if (v[i] >= mn)
            continue;
        mn = v[i];
        ll boost = maxVal - v[i];
        if (rem_health <= boost) {
            pp = min(pp, (ll)i + 1);
            continue;
        }
        auto it = lower_bound(pre.begin() + i, pre.begin() + maxPos, rem_health - boost + v[i]);
        if (it != pre.begin() + maxPos) {
        pp = min(pp, (ll)(it - pre.begin()) + 1);
    }
        
    }
    ll no_swap = n;
auto it0 = lower_bound(pre.begin(), pre.end(), rem_health);
if (it0 != pre.end())
    no_swap = (it0 - pre.begin()) + 1;
    time += min(no_swap, pp);
    cout << time << endl;
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
