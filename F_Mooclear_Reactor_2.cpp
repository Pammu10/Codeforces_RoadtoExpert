#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> particle(n);
    vector<pair<int, int>> shop(m);
    for (int i = 0; i < n; i++)
    {
        int e, r;
        cin >> e >> r;
        particle[i] = {e, r};
    }
    vector<int> prefixSum(n);
    sort(particle.rbegin(), particle.rend());
    prefixSum[0] = particle[0].first;
    for (int i = 0; i < n; i++){
        
    }

    
    for (int i = 0; i < m; i++){
        int e, r;
        cin >> e >> r;
        shop[i] = {e, r};
    }
    deque<int> right;
    deque<int> middle;
    deque<int> left;
    if (x == 0 && y == n)
    {
        int ind = findMin(v);
        rightShift(v, ind, n);
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
    }
    else
    {
        for (int i = 0; i < x; i++)
        {
            left.push_back(v[i]);
        }
        for (int i = y; i < n; i++)
        {
            right.push_back(v[i]);
        }
        for (int i = x; i < y; i++)
        {
            middle.push_back(v[i]);
        }
        // right.front()
        // middle.back()
        // middle.front()
        // left.back()
        int ind = findMin(middle);
        if (ind != -1)
            rightShift(middle, ind, middle.size());
        while (left.size() > 0 && middle.size() > 0 && left.back() > middle.back())
        {
            right.push_front(left.back());
            left.pop_back();
        }
        while (right.size() > 0 && middle.size() > 0 && right.front() < middle.front())
        {
            left.push_back(right.front());
            right.pop_front();
        }

        vector<int> ans;
        while (left.size() > 0)
        {
            ans.push_back(left.front());
            left.pop_front();
        }
        while (middle.size() > 0)
        {
            ans.push_back(middle.front());
            middle.pop_front();
        }
        while (right.size() > 0)
        {
            ans.push_back(right.front());
            right.pop_front();
        }
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
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
