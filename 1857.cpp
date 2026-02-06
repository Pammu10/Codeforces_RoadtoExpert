#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int evenCount = 0;
        int oddCount = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < n; i++){
            if (a[i] % 2 == 0) evenCount++;
            else oddCount++;
        }
        if (oddCount % 2 == 0) cout << "YES" << endl;
        else cout <<"NO" << endl;
    }
    return 0;
}