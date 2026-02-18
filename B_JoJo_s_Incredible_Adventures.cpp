#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    long long n = s.size();
    int maxi = 0;
    int i = 0;
    while (i < n){
        if (s[i] == '0'){
            i++;
            continue;
        }
        int j = i + 1;
        while (j < n && s[j] == '1'){
            j++;
        }
        maxi = max(maxi, j - i);
        i = j;
    }
    if (maxi == n){
        cout << n * n << endl;
        return;
    }
    if (s[0] == '1' && s[n-1] == '1'){
        int i = 0;
        int j = n - 1;
        int cnt = 0;
        while (i < n && s[i] == '1'){
            i++;
            cnt++;
        }
        while (j >= 0 && s[j] == '1'){
            j--;
            cnt++;
        }
        maxi = max(maxi, cnt);
    }
    maxi++;
    long long temp = (maxi + 1) / 2;
    cout << temp * (maxi / 2) << endl;
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
