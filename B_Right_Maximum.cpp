#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    stack<int> st;
    for (int i = n - 1; i >= 0; i--){
        while (!st.empty() && st.top() < v[i]){
            st.pop();
        }
        st.push(v[i]);
    }
    cout << st.size() << "\n";

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
