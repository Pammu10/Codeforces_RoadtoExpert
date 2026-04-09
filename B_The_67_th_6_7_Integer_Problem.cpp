#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    int n = 7;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int sum = 0;

    for (int i = 0; i < n - 1; i++)
    {
        sum += ((-1) * v[i]);
    }
    sum += v[n - 1];
    cout << sum << "\n";
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
