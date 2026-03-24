#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t; 
    vector<int> isPossible(1e6 + 1, 0);
    for (ll i = 2; i <= 10000; i++){
        ll current = i*i*i;
        ll current1 = (current - 1) / (i - 1);
        while (current1 <= 1e6) { 
			isPossible[current1] = 1; 
			current *= i; 
			current1 = (current - 1) / (i - 1);
		}
    }
    while (t--) {
        int n;
    cin >> n;
    if (isPossible[n]) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
    }

    return 0;
}
