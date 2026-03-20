#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> infected(m);
    for (int i = 0; i < m; i++)
    {
        cin >> infected[i];
    }
    sort(infected.begin(), infected.end());
    vector<ll> gaps;
    gaps.push_back(infected[0] + (n - infected[m - 1] - 1));
    for (int i = 1; i < m; i++)
    {
        gaps.push_back(infected[i] - infected[i - 1] - 1);
    }
    sort(gaps.rbegin(), gaps.rend());
    int saved = 0;
    int days = 0;
    for (ll gap : gaps)
    {
        int curGap = gap - days * 2;
        if (curGap > 0)
        {
            saved++;
            curGap -= 2;
            if (curGap > 0)
            {
                saved += curGap;
            }
            days += 2;
        }
    }
    cout << n - saved << "\n";
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
