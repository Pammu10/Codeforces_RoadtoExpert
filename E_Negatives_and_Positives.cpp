#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int neg = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        if (ele < 0)
        {
            neg++;
            ele = -1 * ele;
        }
        v[i] = ele;
        sum += ele;
    }
    sort(v.begin(), v.end());
    if (neg & 1)
    {
        sum -= 2 * v[0];
    }
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
