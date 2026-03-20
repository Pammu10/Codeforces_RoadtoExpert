#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<ll, int> mpp;
    for (int i = 0; i < n; i++)
    {
        ll ele;
        cin >> ele;
        mpp[ele]++;
    }
    int ans = 0;
    for (auto &it : mpp)
    {

        ans += max(0, mpp[it.first] - mpp[it.first - 1]);
    }

    cout << ans << "\n";
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
