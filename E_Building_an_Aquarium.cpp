#include <bits/stdc++.h>

using namespace std;


bool checkWater(vector<int> &v, long long x, long long mid){
    long long totalNeeded = 0;
    for (int h : v) {
        if (mid > h) {
            totalNeeded += (mid - h);
        }
        if (totalNeeded > x) return false;
    }
    return totalNeeded <= x;
}

void solve() {
    long long n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    long long high = 1e12;
    long long low = 1;
    long long ans = -1;
    while (low <= high){
        long long mid = (high - low) / 2 + low;
        if (checkWater(v, x, mid)){
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
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
