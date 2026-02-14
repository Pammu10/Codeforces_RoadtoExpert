#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long sum = a[0];
    long long maxSum = a[0];
    for (int i = 1; i < n; i++)
    {
        if (((a[i] ^ a[i - 1]) & 1) == 0)
        {
            sum = a[i];
        }
        else
        {
            sum = max((long long)a[i], sum + a[i]);
            
        }maxSum = max(sum, maxSum);
        }
    cout << maxSum << endl;
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
