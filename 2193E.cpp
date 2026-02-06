#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--){
        int n; 
        cin >> n;
        vector<int>a(n+1);
        vector<int> dp(n + 1, 1e9 + 7);
        for (int i = 1; i <= n; i++) cin >> a[i], dp[a[i]] = 1;
        for (int x = 1; x <= n; x++){
            for (int y = x; y <= n; y += x){
                dp[y] = min(dp[y], dp[x] + dp[y/x]);
                }    
            }

        for (int i = 1; i <= n; i++){
            if (dp[i] == 1e9+7) dp[i] = -1;
        }
        for (int i = 1; i <= n; i++){
            cout << dp[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
