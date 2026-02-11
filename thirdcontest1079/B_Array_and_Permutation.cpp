#include <bits/stdc++.h>

using namespace std;

void solve() {
    // Your problem-solving code goes here
    long long n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    for (long long i = 0; i < n; i++){
        cin >> a[i];
    }
    for (long long i = 0; i < n; i++){
        cin >> b[i];
    }
    int b_point = 0; //bpointer
    for (long long a_point = 0; a_point < n; a_point++){
        while (b_point < n && b[b_point] == a[a_point]){
            b_point++;
        }
    }
    if (b_point == n){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    // Process input and produce output
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
