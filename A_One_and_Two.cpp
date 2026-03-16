#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    ll cnt = 0;
    for (int i = 0; i < n; i++){
        if (v[i] == 2) cnt++;
    }
    if (cnt == 0){
        cout << 1 << "\n";
    }
    else if (cnt & 1){
        cout << -1 << "\n";
    }
    else {
        ll target = cnt / 2;
        cnt = 0;
        for (int i = 0; i < n; i++){
            if (v[i] == 2){
                cnt++;
                if (cnt == target){
                    cout << i + 1 << "\n";
                    break;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
