#include <bits/stdc++.h>

using namespace std;

void solve() {
    // Your problem-solving code goes here
    long long n, p;
    cin >> n >> p;
    vector<long long> a(n);
    vector<long long> b(n);
    for (int i =0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    vector<pair<long long, long long>> b_cost_count;
    for (int i = 0; i < n; i++){
        b_cost_count.push_back({b[i], a[i]});
    }
    sort(b_cost_count.begin(), b_cost_count.end());
    long long cnt = 1;
    long long cost = p;
    for (auto it : b_cost_count){
        long long extracnt = it.second;
        long long extracost = it.first;

        if (extracost >= p){
            break;
        }
        if (cnt + extracnt > n){
            cost += (n - cnt) * extracost;
            cnt = n;
            break;
        }
        else {
            cost += extracnt * extracost;
            cnt += extracnt;
        }
    }

    cost += (n - cnt) * p;
    cout << cost << endl;


    // Process input and produce output
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t = 1;
    // Uncomment the next line if there are multiple test cases
    cin >> t; 
    while (t--) {
        solve();
    }

    return 0;
}
