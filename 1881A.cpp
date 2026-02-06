#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        string s;
        string x;
        char c;
        for (int i = 0; i < n; i++){
            cin >> c;
            x += c;
        }
        for (int i = 0; i < m; i++){
            cin >> c;
            s += c;
        }
        int count = 0;
        while (x.size() < s.size()){
            x = x + x;
            count++;
        }
        int ans = -1;
        
        for (int i = 0; i < x.size(); i++){
            int j = 0;
            if (x[i] == s[j]){
                while (j < s.size() && x[i + j] == s[j]) j++;
                if (j == s.size()) ans = count; 
            }
        }
        if (ans == -1){
            x = x + x;
            count++;
        }
        for (int i = 0; i < x.size(); i++){
            int j = 0;
            if (x[i] == s[j]){
                while (j < s.size() && x[i + j] == s[j]) j++;
                if (j == s.size()) ans = count; 
            }
        }
       cout << ans << endl;
    }
    return 0;
}