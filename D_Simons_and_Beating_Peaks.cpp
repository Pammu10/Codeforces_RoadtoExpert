#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int LIS(const vector<int>& a) {
    vector<int> dp;
    for (int x : a) {
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) dp.push_back(x);
        else *it = x;
    }
    return dp.size();
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int ind = max_element(v.begin(), v.end()) - v.begin();

    vector<int> left, right;
    for (int i = 0; i < ind; i++) left.push_back(v[i]);
    for (int i = ind + 1; i < n; i++) right.push_back(-v[i]);

    int L = LIS(left);
    int R = LIS(right);

    cout << (n - 1) - (L + R) << "\n";
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
