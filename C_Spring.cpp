#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}


void solve() {
    ll a, b, c, m;
    cin >> a >> b >> c >> m;
    vector<ll> ans;
    ll ab = lcm(a, b);
    ll bc = lcm(b, c);
    ll ac = lcm(a, c);
    ll abc = lcm(a, bc);
    ll numA = m / a;
    ll numB = m / b;
    ll numC = m / c;
    ll numAB = m / ab;
    ll numAC = m / ac;
    ll numBC = m / bc;
    ll numABC = m / abc;
    ll Astar = numA - numAB - numAC + numABC;
    ll Bstar = numB - numAB - numBC + numABC;
    ll Cstar = numC - numAC - numBC + numABC;
    ll ABstar = numAB - numABC;
    ll BCstar = numBC - numABC;
    ll ACstar = numAC - numABC;
    ans.push_back(Astar*6 + ABstar*3 + ACstar*3 + numABC*2);
    ans.push_back(Bstar*6 + ABstar*3 + BCstar*3 + numABC*2);
    ans.push_back(Cstar*6 + BCstar*3 + ACstar*3 + numABC*2);
    cout << ans[0] << " " <<  ans[1] << " " <<  ans[2];
    cout << "\n";
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
