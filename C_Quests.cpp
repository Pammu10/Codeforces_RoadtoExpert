#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    long long total = 0;
    vector<long long> prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = a[i] + prefix[i-1];
    }
    int max_b = b[0];
    for (int i = 0; i < min(n, k); i++)
    {
        max_b = max(max_b, b[i]);
        total = max(total, prefix[i] + (k - i - 1) * max_b);
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
