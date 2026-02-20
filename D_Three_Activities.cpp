#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    ll n;
    cin >> n;
    ll ele;
    vector<pair<ll, ll>> A(n);
    for (int i = 0; i < n; i++){
        cin >> ele;
        A[i] = {ele, i};
    }
    vector<pair<ll, ll>> B(n);
    for (int i = 0; i < n; i++){
        cin >> ele;
        B[i] = {ele, i};
    }
    vector<pair<ll, ll>> C(n);
    for (int i = 0; i < n; i++){
        cin >> ele;
        C[i] = {ele, i};
    }
    sort(A.rbegin(), A.rend()); 
    sort(B.rbegin(), B.rend());
    sort(C.rbegin(), C.rend());
    ll maxAns = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 3; k++){
                ll x = A[i].second;
                ll y = B[j].second;
                ll z = C[k].second;
                if ((x == y) || (x == z) || (y == z)) continue;
                maxAns = max(maxAns, A[i].first + B[j].first + C[k].first);
            }
        }
    }
    cout << maxAns << endl;
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
