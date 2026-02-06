#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n; int k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int j = 1;
        while (j < a.size()){
            if (a[j-1] > a[j]){
                break;
            }
            j++;
        }
        if (j == n){
            cout << "YES" << endl;
        } 
        else if (k >= 2){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        
    }
    return 0;
}