#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    if (v.size() == 1) cout << 1 << endl;
    else {
        vector<int> ans;
        ans.push_back(v[0]);
        ans.push_back(v[1]);
        for (int i = 2; i < n; i++){
            int curSize = ans.size();
            int x = ans[curSize - 2] - ans[curSize - 1];
            int y = ans[curSize - 1] - v[i]; 

            if (x > 0){
                if (y > 0){
                    ans[curSize - 1] = v[i];
                }
                else if (y < 0){
                    ans.push_back(v[i]);
                }
            }
            else {
                if (y > 0){
                    ans.push_back(v[i]);
                }
                else {
                    ans[curSize - 1] = v[i];
                }
            }
        }
        int finalSize = ans.size();
        if (ans[0] == ans[1])
			finalSize--;
        cout << finalSize << endl;
    }
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    while (t--) {
        solve();
    }

    return 0;
}
