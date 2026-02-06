#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        char c;
        string str;
        for (int i = 0; i < n; i++){
            cin >> c;
            str += c;
        }
        int maxCons = 0;
        int cons = 0;
        int count = 0;
        for (char c : str){
            if (c == '.'){
                cons++;
                count++;
                maxCons = max(maxCons, cons);
            }
            else {
                cons = 0;
            }
        }
        if (count == 0) {
            cout << 0 << endl;
        }
        else if (maxCons >= 3){
            cout << 2 << endl;
        }
        else {
            cout << count << endl;
        }
    }
    return 0;
}