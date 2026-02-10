#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
    int t;
    cin >> t;
    while (t--){
        int n; 
        cin >> n;
        vector<int> a(n);
        vector<int> sorteda(n);
        int data;
        for (int i = 0; i < n; i++){
            cin >> data;
            a[i] = data;
            sorteda[i] = data;
        }
        sort(sorteda.begin(), sorteda.end());
        if (sorteda == a) cout << -1 << endl;
        else {
            int leastk = INT_MAX;
            for (int i = 0; i < n; i++){
                if (a[i] != sorteda[i]){
                    leastk = min(leastk, max(a[i] - sorteda[0], sorteda[n - 1] - a[i]));
                }
            }
            cout << leastk << " " << endl;
        }
        
    }
    
    return 0;
}