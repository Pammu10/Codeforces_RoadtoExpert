#include <bits/stdc++.h>

using namespace std;

void solve()
{
    // Your problem-solving code goes here
    long long p, q;
    cin >> p >> q;
    
    long long multiplier = p / 2;
    long long prev_multiplier = multiplier - 1;
    long long upper_bound = multiplier * __int128(3);
    long long lower_bound = prev_multiplier * __int128(3);
    if (upper_bound >= q && q > lower_bound)
    {
        cout << "Bob" << endl;
    }
    else
        cout << "Alice" << endl;

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
