#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i]; 
        }
        int minDist = a[0];
        for (int i  = 1; i < a.size(); i++){
            minDist = max(minDist, a[i] - a[i-1]);
        }
        minDist = max(minDist, 2*(x - a[n-1]));
        cout << minDist << endl;
    }
    return 0;
}