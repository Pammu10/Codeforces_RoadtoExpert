#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int minDif = 1e9;
        bool sorted = true;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            if (i > 0){
                minDif = min(minDif, a[i] - a[i-1]);
                sorted &= a[i] >= a[i - 1];
            }
        }
        

         if (!sorted) {
            cout << 0 << endl;
            continue;
        }
    
        cout << minDif/2 + 1 << endl;
    }
    return 0;
}