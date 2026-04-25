#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> v_odd, v_even;
    ll total_sum = 0;
    for (int i = 1; i <= n; i++) {
        ll val;
        cin >> val;
        total_sum += val;
        if (i % 2 != 0) v_odd.push_back(val);
        else v_even.push_back(val);
    }
    int m_odd = 0, m_even = 0;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (x % 2 != 0) m_odd++;
        else m_even++;
    }
    sort(v_odd.rbegin(), v_odd.rend());
    sort(v_even.rbegin(), v_even.rend());
    ll marked_sum = 0;
    if (m_odd > 0 && !v_odd.empty()) {
        marked_sum += v_odd[0];
        for (int i = 1; i < v_odd.size() && i < m_odd; i++) {
            if (v_odd[i] > 0) marked_sum += v_odd[i];
            else break;
        }
    }
    if (m_even > 0 && !v_even.empty()) {
        marked_sum += v_even[0];
        for (int i = 1; i < v_even.size() && i < m_even; i++) {
            if (v_even[i] > 0) marked_sum += v_even[i];
            else break;
        }
    }
    cout << total_sum - marked_sum << endl;
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