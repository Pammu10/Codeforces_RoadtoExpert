#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int r, g, b;
    cin >> r >> g >> b;

    int counts[3] = {r, g, b};
    char chars[3] = {'R', 'G', 'B'};

    string s = "";
    int total = r + g + b;
    
    for (int i = 0; i < total; ++i) {
        int best_c = -1;
        
        for (int c = 0; c < 3; ++c) {
            if (counts[c] == 0) continue;
            if (i >= 1 && s[i - 1] == chars[c]) continue;
            if (i >= 3 && s[i - 3] == chars[c]) continue;

            if (best_c == -1) {
                best_c = c;
            } else {
                
                if (counts[c] > counts[best_c]) {
                    best_c = c;
                } 
                else if (counts[c] == counts[best_c]) {
                    bool c_matches_s2 = (i >= 2 && s[i - 2] == chars[c]);
                    bool best_matches_s2 = (i >= 2 && s[i - 2] == chars[best_c]);
                    
                    if (c_matches_s2 && !best_matches_s2) {
                        best_c = c;
                    }
                }
            }
        }

        if (best_c == -1) {
            break;
        }

        s += chars[best_c];
        counts[best_c]--;
    }

    cout << s << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}