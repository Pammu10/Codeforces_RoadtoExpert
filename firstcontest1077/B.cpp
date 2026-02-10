//done
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
    int t;
    cin >> t;
    while (t--){
        int n; 
        cin >> n;
        string s;
        cin >> s;
        int initones = 0;
        for (char c : s){
            if (c == '1') initones++;
        }
        int count = 0;
        int i = 0;
        if (initones == 0){
            cout << ceil((double)n / 3) << endl;
        }

        else {
            
            while (i < n){
                if (s[i] == '1') {i++; continue;}
                int j = i;
                while (j < n && s[j] != '1') j++;
                int len = j - i;
                bool leftOne = (i > 0 && s[i-1] == '1'); 
                bool rightOne = (j < n && s[j] == '1');

                if (rightOne && leftOne){
                    if (len > 2){
                        count += ceil((double)(len - 2) / 3);
                    }
                }
                else {
                    if (len > 1){
                        count += ceil((double)(len - 1) / 3);
                    }
                }
                i = j;
            }
            cout << initones + count << endl;
        }
        
    }
    
    return 0;
}