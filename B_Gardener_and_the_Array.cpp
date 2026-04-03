#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t; 
    while (t--)
    {
        int n;
        cin >> n;              
        map<int, int> mp;      
        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
        { 
            int x;
            cin >> x;            
            vector<int> temp(x); 
            for (int j = 0; j < x; j++)
            {
                cin >> temp[j];
                mp[temp[j]]++; 
            }
            v.push_back(temp);
        }
        string ans = "No"; 
        for (int i = 0; i < n; i++)
        {              
            int f = 1;
            for (auto it : v[i])
            {
                if (mp[it] == 1)
                {        
                    f = 0; 
                    break; 
                }
            }
            if (f == 1)
            {             
                ans = "Yes";
                break;       
            }
        }
        cout << ans << endl; 
    }
}

