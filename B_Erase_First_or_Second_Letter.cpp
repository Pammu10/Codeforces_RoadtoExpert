#include <bits/stdc++.h>

using namespace std;

void solve()
{
    // Your problem-solving code goes here
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> freq(26, 0);
    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (freq[str[i] - 'a'] == 0){
            cnt += n - i;
        }
        freq[str[i] - 'a']++;
    }
    cout << cnt << endl;
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
