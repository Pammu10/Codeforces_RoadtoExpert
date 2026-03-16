#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int ele;
            cin >> ele;
            mpp[ele]++;
        }
    }
    long long maxCount = 0;
    for (auto it : mpp){
        maxCount = max(maxCount, (long long)it.second);
    }
    long long threshold = n * (n - 1);;
    if (maxCount <= threshold){
        cout << "YES\n";
    }
    else {
        cout <<"NO\n";
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
