#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool cmp(pair<ll, int> &a, pair<ll, int> &b)
{
    return a.first < b.first;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<ll, int>> v(n);
    ll ele;
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        v[i] = {ele, i};
    }
    sort(v.begin(), v.end(), cmp);
    vector<ll> prefix(n);
    prefix[0] = v[0].first;
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + v[i].first;
    }
    vector<int> ans(n);
    ans[v[n-1].second] = n-1;
    for (int i = n-2; i >= 0; i--){
        long long cmp = v[i+1].first;
        if (prefix[i] >= cmp){
            ans[v[i].second] = ans[v[i+1].second];
        }
        else {
            ans[v[i].second] = i;
        }
    }
    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
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
