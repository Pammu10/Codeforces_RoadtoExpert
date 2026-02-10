#include <bits/stdc++.h>

using namespace std;

void solve() {
    // Your problem-solving code goes here
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    int count_zero = 0;
    for (int i = 0; i < n; i++){
        if (v[i] == 0){
            count_zero++;
        }
    }
    int left = 0;
    int right = n - 1;
    while (left < n && v[left] == 0){
        left++;
    }
    while (right > 0 && v[right] == 0){
        right--;
    }
    bool found = 0;
    for (int i = left; i <= right; i++){
        if (v[i] == 0){
            found = 1;
        }
    }

    if (count_zero == n){
        cout << 0 << endl;
    }
    else if (found == 0){
        cout << 1 << endl;
    }
    else {
        cout << 2 << endl;
    }
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
