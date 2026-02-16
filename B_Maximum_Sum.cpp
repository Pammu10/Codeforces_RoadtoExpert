#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<ll> prefix(n);
    prefix[0] = v[0];
    for (ll i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + v[i];
    }
    ll total = 0;
    for (int first = 0; first <= k; first++)
    {
        int second = k - first;
        int left = first * 2;
        int right = n - second - 1;
        ll sum = prefix[right] - ((left == 0) ? 0 : prefix[left - 1]);
        total = max(total, sum);
    }
    cout << total << endl;
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
