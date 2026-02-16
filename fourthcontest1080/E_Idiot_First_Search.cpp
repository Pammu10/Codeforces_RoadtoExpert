#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n + 1);
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v[i + 1] = {a, b};
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
