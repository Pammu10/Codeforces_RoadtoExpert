#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t; // Read the number of test cases
    while (t--)
    {
        long long n, k, b, s;
        cin >> n >> k >> b >> s; // Read n, k, b, s for each test case

        // Calculate the minimum and maximum possible sum s
        long long minimum_s = (k * b);
        long long maximum_s = (k * b) + (k - 1) * n;

        
        if (s < minimum_s || s > maximum_s)
            cout << "-1" << endl; // If not, print -1
        else
        {
            vector<long long> ans(n, 0); 
            ans[0] = minimum_s;          
            s -= minimum_s;             

            
            for (int i = 0; i < n; i++)
            {
                long long add = min(k - 1, s); 
                ans[i] += add;                
                s -= add;                    
            }

            // Output the resulting array
            for (long long i = 0; i < n; i++)
                cout << ans[i] << " ";
            cout << endl;
        }
    }

}
