#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        vector<bool> visited(n + 1, false);
        bool ok = true;

        for (int i = 1; i <= n; i++)
        {
            if (visited[i])
                continue;

            vector<int> idx, vals;
            int x = i;
            while (x <= n)
            {
                visited[x] = true;
                idx.push_back(x);
                vals.push_back(a[x]);
                x *= 2;
            }

            sort(idx.begin(), idx.end());
            sort(vals.begin(), vals.end());

            if (idx != vals)
            {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
