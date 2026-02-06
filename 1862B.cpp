#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        b.push_back(a[0]);
        for (int i = 1; i < a.size(); i++){
            if (a[i] < a[i-1]){
                b.push_back(1);
            }
            b.push_back(a[i]);
        }
        cout << b.size() << endl;
        for (int i = 0; i < b.size(); i++){
            cout << b[i] << " ";
        }
        cout << endl;
    }
    return 0;
}