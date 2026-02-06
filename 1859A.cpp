#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if (a[0] == a[n-1]) cout << -1;
        else {
            int j = n -  2;
            while (j > 0 && a[j] == a[j + 1]) j--;
            j++;
            cout << j << " " << n - j << endl;
            for (int i = 0; i < j; i++){
                cout << a[i] << " ";
            }
            cout << endl;
            for (int i = j; i < n; i++){
                cout << a[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}