#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n == 67){
        cout << n << "\n";
    }
    else 
    cout << n + 1 << "\n";
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
