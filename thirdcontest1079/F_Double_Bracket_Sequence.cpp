#include <bits/stdc++.h>

using namespace std;

void solve() {
    // Your problem-solving code goes here
    int n;
    cin >> n;
    string str;
    cin >> str;
    long long cnt = 0;
    //for ()
    stack<char> st;
    for (int i = 0; i < n; i++){
         if (str[i] == '(' || str[i] == ')'){
        while (!st.empty() && st.top() == '('){
            st.pop();
        }
        st.push(str[i]);
    }
    }
    //for []
    cnt += st.size();
    while (!st.empty()) st.pop();
    for (int i = 0; i < n; i++){
        if (str[i] == '[' || str[i] == ']'){
            while (!st.empty() && st.top() == ']'){
            st.pop();
        }
        st.push(str[i]);
        }
        
    }
    cnt += st.size();
    cout << cnt << endl;

    // Process input and produce output
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // Uncomment the next line if there are multiple test cases
    cin >> t; 
    while (t--) {
        solve();
    }

    return 0;
}
