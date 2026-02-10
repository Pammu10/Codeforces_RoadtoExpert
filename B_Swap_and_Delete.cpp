#include <bits/stdc++.h>

using namespace std;

void solve()
{
    // Your problem-solving code goes here
    string s;
    cin >> s;
    int n = s.size();
    int zero_count = 0;
    int one_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            zero_count++;
        else
            one_count++;
    }
    int t_count = 0;
    for (int i = 0; i < n; i++)
        {
            if (s[i] == '0' && one_count> 0)
			{
				one_count--; // Use a '1' to make a pair with '0'
				t_count++; // Increase the length of the good string
			}
			else if (s[i] == '1' && zero_count > 0)
			{
				zero_count--; // Use a '0' to make a pair with '1'
				t_count++; // Increase the length of the good string
			}
			else
			{
				break; // No more pairs can be formed
			}
        
        
    }
 cout << n - t_count << endl;
   
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
