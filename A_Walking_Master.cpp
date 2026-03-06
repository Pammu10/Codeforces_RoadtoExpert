#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (d - b >= 0)
    {
        int moves = 0;
        moves += (d - b);
        if (a + moves < c)
        {
            cout << -1 << endl;
        }
        else
        {
            moves += a + moves - c;
            cout << moves << endl;
        }
    }
    else
    {
        cout << -1 << endl;
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
