#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> f(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> f[i];
        }

        vector<long long> a(n + 1, 0);

        if (n == 2) {
            a[1] = f[2];
            a[2] = f[1];
        } else {
            for (int i = 2; i <= n - 1; i++) {
                a[i] = ((f[i + 1] - f[i]) - (f[i] - f[i - 1])) / 2;
            }

            long long midSum = 0;
            for (int i = 2; i <= n - 1; i++) {
                midSum += a[i];
            }
            long long S = (f[1] + f[n]) / (n - 1);
            a[1] = (S + (f[2] - f[1])) / 2;
            a[n] = S - a[1] - midSum;
        }

        for (int i = 1; i <= n; i++) {
            cout << a[i] << (i == n ? '\n' : ' ');
        }
    }
    return 0;
}
