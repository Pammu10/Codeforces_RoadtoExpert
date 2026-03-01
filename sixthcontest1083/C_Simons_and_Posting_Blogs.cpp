#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<ll>> v(n);
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        int ele;
        set<ll> st;
        vector<ll> temp(l);
        for (int j = 0; j < l; j++)
        {
            cin >> temp[j];
        }
        for (int j = l - 1; j >= 0; j--)
        {
            if (st.find(temp[j]) == st.end())
            {
                st.insert(temp[j]);
                v[i].push_back(temp[j]);
            }
        }
    }
    vector<ll> ans;
    vector<bool> used(n, false);
    for (int i = 0; i < n; i++)
    {
        ll ind = -1;
        for (int j = 0; j < n; j++)
        {
            if (!used[j])
            {
                if (ind == -1 || v[j] < v[ind])
                {
                    ind = j;
                }
            }
        }
        if (ind == -1)
            break;
        used[ind] = true;
        set<ll> tempset(v[ind].begin(), v[ind].end());
        for (auto &it : v[ind])
            ans.push_back(it);
        for (int j = 0; j < n; j++)
        {
            if (!used[j])
            {
                vector<ll> temp;
                for (int k = 0; k < v[j].size(); k++)
                {
                    if (tempset.find(v[j][k]) == tempset.end())
                    {
                        temp.push_back(v[j][k]);
                    }
                }
                v[j] = temp;
            }
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
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
