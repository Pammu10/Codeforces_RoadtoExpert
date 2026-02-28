#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        int ele;
        for (int j = 0; j < l; j++)
        {
            cin >> ele;
            v[i].push_back(ele);
        }
        reverse(v[i].begin(), v[i].end());
    }
     
    for (int i = 0; i < n; i++){
        for (int j = 0; j < v[i].size(); j++)
        {
            if (res.find(v[i][j]) == res.end()){
                res[v[i][j]]++;
            }
        }
    }
    vector<int> ress;
    for (auto it : res)
    {
        
        ress.push_back(it.first);
    }
    reverse(ress.begin(), ress.end());
    for (int i = 0; i < ress.size(); i++){
        cout << ress[i] << " ";
    }
    cout << endl;
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
