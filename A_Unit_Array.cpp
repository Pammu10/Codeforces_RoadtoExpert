#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        if (ele > 0)
            cnt1++;
        else
            cnt0++;
    }
    int sum = cnt1 - cnt0;
    if (cnt0 % 2 == 0 && sum >= 0)
    {
        cout << 0 << "\n";
    }
    else
    {
        int cnt = 0;
        while (sum < 0)
        {
            cnt++;
            cnt0--;
            sum += 2;
        }
        if (cnt0 % 2 != 0)
        {
            if (sum >= 0)
            {
                cnt += 1;
            }
        }
        cout << cnt << "\n";
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
