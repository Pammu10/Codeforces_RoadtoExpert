#include <bits/stdc++.h>

using namespace std;

void solve() {
    // Your problem-solving code goes here
    int n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    long long ans = LLONG_MAX;
    int even_count = 0;
        for (int i = 0; i < n; i++){
            if (v[i] % 2 == 0){
                even_count++;
            }
            if (v[i] % k == 0){
                ans = 0;
            }
            ans = min(ans, k - (v[i] % k));
        }
    
    if (k == 4){
        
        if (even_count == 0){
            ans = min(ans, 2LL);
        }
        else if (even_count == 1){
            ans = min(ans, 1LL);
        }
        else if (even_count >= 2) {
            ans = min(ans, 0LL);
        }
    }
    cout << ans << endl;
    // Process input and produce output
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // Uncomment the next line if there are multiple test cases
    cin >> t; 
    while (t--) {
        solve();
    }

    return 0;
}
