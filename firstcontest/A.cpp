//done
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
    int t;
    cin >> t;
    while (t--){
        int n; 
        cin >> n;
        vector<int> ans;
        ans.push_back(1);
        ans.push_back(n);
        n = n - 2;
        int i = 0;
        while (n){
            if (i % 2 == 0) ans.push_back(ans.back() - n);
            else ans.push_back(ans.back() + n);
            i++;
            n--;
        }
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}