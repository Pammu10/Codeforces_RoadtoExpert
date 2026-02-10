#include <bits/stdc++.h>

using namespace std;
void solve()
{
    // Your problem-solving code goes here
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    int cnt = 0;
    for (int i = n - 2; i >= 0; i--){
        while (v[i] > 0 && v[i] >= v[i+1]){
            v[i] = v[i]/ 2;
            cnt++;
            if (v[i] == 0){
            break;
        }
        }
        if (v[i] == 0 && v[i+1] == 0){
            cnt = -1;
            break;
        }
        
    }
    cout << cnt << endl;
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
