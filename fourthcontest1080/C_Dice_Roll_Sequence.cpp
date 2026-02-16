#include <bits/stdc++.h>

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
    long long count = 0;
    int prev = v[0];
    int i = 1;
    while (i < n){
        if (v[i] == prev || v[i] == (7 - prev)){
            count++;
            i += 2;
            if (i >= n) break;
            prev = v[i-1];
        }
        else {
            prev = v[i];
            i++;
            
        }
    }
    cout << count << endl;
    
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
