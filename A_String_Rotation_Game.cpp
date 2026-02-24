#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != s[(i + 1) % n]) {
            cnt++;
        }
    }

    // if ()
    if (cnt == 0) cout << 1 << "\n";
    else if (cnt == n) cout << cnt << "\n";
    else cout << cnt + 1 << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}