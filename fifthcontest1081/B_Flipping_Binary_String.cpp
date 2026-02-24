#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll cnt1 = 0;
    ll cnt0 = 0;
    vector<int> index1;
    vector<int> index0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            cnt1++;
            index1.push_back(i + 1);
        }
        else
        {
            cnt0++;
            index0.push_back(i + 1);
        }
    }
    if (cnt0 % 2 == 1)
    {
        cout << index0.size() << endl;
        for (int i = 0; i < index0.size(); i++)
            cout << index0[i] << " ";
        if (index0.size() != 0)
            cout << endl;
    }
    else if (cnt1 % 2 == 0)
    {
        cout << index1.size() << endl;
        for (int i = 0; i < index1.size(); i++)
        {
            cout << index1[i] << " ";
        }
        if (index1.size() != 0)
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
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
