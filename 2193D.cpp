#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--){
        int n; 
        cin >> n;
        vector<int>a(n); vector<int>b(n+1);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> b[i];
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        long long ans = 0; int h = 0; int sum = 0;
        for (int i = 0; i < n; i++){
            while (h < n && sum + b[h + 1] <= i + 1) h++, sum += b[h];
            ans = max(ans, a[i] * 1LL * h);
        }

        cout << ans << "\n";
        
    }
    return 0;
}
