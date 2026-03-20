#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    set<int> st(v.begin(), v.end());

    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (v[i] == *st.begin() || v[i] == *st.rbegin())
        {
            st.erase(v[i]);
            i++;
            continue;
        }
        if (v[j] == *st.begin() || v[j] == *st.rbegin())
        {
            st.erase(v[j]);
            j--;
            continue;
        }
        break;
    }
    if (i < j)
        cout << i + 1 << " " << j + 1 << "\n";
    else
        cout << -1 << "\n";
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
