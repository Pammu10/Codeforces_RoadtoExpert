#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--){
        int n, q;
        cin >> n >> q;
        vector<int> a(n); vector<int> b(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < n; i++){
            cin >> b[i];
        }
        a.push_back(0);
        for (int i = n-1; i >= 0; i--){
            a[i] = max({a[i + 1], a[i], b[i]});
        }
        vector<int> prefixMaxArray(n + 1);
        prefixMaxArray[0] = 0;
        for (int i = 1; i <= n; i++){
            prefixMaxArray[i] = prefixMaxArray[i - 1] + a[i - 1];
        }
        for (int i = 0; i < q; i++){
            int l, r;
            cin >> l >> r;
            cout << prefixMaxArray[r] - prefixMaxArray[l-1] << endl;
        }
    }
    return 0;
}