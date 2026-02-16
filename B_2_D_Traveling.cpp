#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    ll n, k, a, b;
    cin >> n >> k >> a >>b;
    vector<pair<ll, ll>> cities(n+1);
    // vector<ll> x(n+1);
    for (int i = 1; i <= n; i++){
        cin >> cities[i].first >> cities[i].second;
    } 
    ll dist = abs(cities[a].first - cities[b].first) + abs(cities[a].second - cities[b].second);
    ll minA = 1e17;
    ll minB = 1e17;

    for (int i = 1; i <= k; i++){
        minA = min(minA, abs(cities[a].first - cities[i].first) + abs(cities[a].second - cities[i].second));
        minB = min(minB, abs(cities[b].first - cities[i].first) + abs(cities[b].second - cities[i].second));
    }
    dist = min(dist, minA + minB);
    cout << dist << endl;
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
