#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--){
        int n, Ax, Ay, Bx, By; 
        cin >> n >> Ax >> Ay >> Bx >> By;
        vector<int>x(n+1);
        vector<int>y(n+1);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9 + 7));
        for (int i = 1; i <= n; i++) cin >> x[i];
        for (int i = 1; i <= n; i++) cin >> y[i];
        dp[Ax][Ay] = 0;
        vector<pair<int, int>> points;
        for (int i = 1; i <= n; i++){
            points.push_back({x[i], y[i]});
        }
        sort(points.begin(), points.end());
        
        return dp[Bx][By];
        cout << endl;
    }
    return 0;
}
