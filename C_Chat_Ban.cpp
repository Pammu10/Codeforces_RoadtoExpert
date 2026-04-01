#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll findFirstSum(ll num)
{
    return num * (num + 1) / 2;
}

void solve()
{
    ll k, x;
    cin >> k >> x;
    ll low = 0;
    ll high = 2 * k - 1;
    ll ans = 2 * k - 1;
    while (low <= high)
    {
        ll mid = (low + high) / 2;
        ll cnt;
        if (mid >= k)
        {
            cnt = findFirstSum(k) + findFirstSum(k - 1) - findFirstSum(2 * k - 1 - mid);
        }
        else
        {
            cnt = findFirstSum(mid);
        }

        if (cnt >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
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
