#include <bits/stdc++.h>

using namespace std;

void solve()
{
    // Your problem-solving code goes here
    int n, k;
    cin >> n >> k;
    vector<int> vec(26, 0);
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        vec[s[i] - 'a']++;
    }
    int evenCount = 0;
    int oddCount = 0;
    for (int i = 0; i < 26; i++)
    {
        if (vec[i] > 0)
        {
            if (vec[i] % 2 == 0)
                evenCount++;
            else
                oddCount++;
        }
    }
    if (oddCount > k + 1)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    // Process input and produce output
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // Uncomment the next line if there are multiple test cases
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
