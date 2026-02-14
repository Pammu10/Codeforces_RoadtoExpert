#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    // Your problem-solving code goes here
    long long n, x;
    cin >> n >> x;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<pair<long long, long long>> segments;
    for (ll i = 0; i < n; i++){
        segments.push_back({v[i] - x, v[i] + x});
    }
    long long count= 0;
    ll l = segments[0].first;
    ll r = segments[0].second;

    for (ll i = 1; i < n; i++){
        l = max(l, segments[i].first);
        r = min(r, segments[i].second);
        if (l > r){
            count++;
            l = segments[i].first;
            r = segments[i].second;
        }
    }

    cout << count << endl;
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
