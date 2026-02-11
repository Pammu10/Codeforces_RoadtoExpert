#include <bits/stdc++.h>

using namespace std;

void solve() {
    // Your problem-solving code goes here
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++){
        cin >> v[i];
    }
    long long count = 0;
    for (long long i = n - 1; i >= 0; i--){
        long long k = i;
        while (k > 0){
            k = k - v[i];
            if (k >= 0 && v[k] * v[i] == i - k) count++;
        }
    }
    cout << count << endl;
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
