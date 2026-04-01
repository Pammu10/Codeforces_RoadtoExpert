#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    
    auto get_L = [&](string str) {
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            if (str[i] == '(' && str[i+1] == ')') cnt++;
        }
        return cnt;
    };
    
    auto get_D = [&](string str) {
        int fst = -1, lst = -1;

        for (int i = 0; i < n - 1; i++) {
            if (str[i] == '(' && str[i+1] == ')') {
                if (fst == -1) fst = i;
                lst = i;
            }
        }
        
        int cur = 0;
        int fst_depth = 0;
        vector<int> deps(n);
        
        for (int i = 0; i < n; i++) {
            if (str[i] == '(') {
                if (i == fst) fst_depth = cur;
                cur++;
            } else {
                cur--;
            }
            deps[i] = cur;
        }
        
        if (fst == lst) return fst_depth;
        
        int mn = 1e9;
        for (int i = fst + 1; i < lst; i++) {
            mn = min(mn, deps[i]);
        }
        
        return mn;
    };
    
    if (get_L(s) == get_L(t) && get_D(s) == get_D(t)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}