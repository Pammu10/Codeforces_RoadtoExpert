#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            mpp[a[i]]++;
        }
        if (mpp.size() == 1){
            cout << "YES" << endl;
        }
        else if (mpp.size() > 2){
            cout << "NO" << endl;
        }
        else {
            int first;
            int second;
            int i = 0;
            for (auto it : mpp){
                if (i == 0) first = it.second;
                else second = it.second;
                i++;
            }
            if (abs(first - second) > 1) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
       
   
} return 0;
}