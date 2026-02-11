#include <bits/stdc++.h>

using namespace std;

int digitSum(long long y){
    long long sum = 0;
    while (y > 0){
        sum += y % 10;
        y = y / 10;
    }
    return sum;

}


void solve() {
    // Your problem-solving code goes here
    long long x;
    cin >> x;
    // Process input and produce output
    long long count = 0;

    for (long long y = x; y <= x + 162; y++) {
        if (y - digitSum(y) == x) {
            count++;
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
