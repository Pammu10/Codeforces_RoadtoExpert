#include<bits/stdc++.h>

using namespace std;


void upd(long long _p, long long _q, long long x, long long y, long long &min, long long &p, long long  &q){
    if ((_p & _q) == 0 && abs(_p - x) + abs(_q - y) < min){
        min = abs(_p - x) + abs(_q - y);
        p = _p;
        q = _q;
    }
}


void solve(){
    long long x, y;
    long long p, q;
    cin >> x >> y;
    long long min = LLONG_MAX;
    upd(x, y, x, y, min, p, q);
    for (int i = 29; i>= 0; i--){
        if (((x >> i) & 1) && ((y >> i) & 1)){
            upd((x >> i << i) + (1LL << i), y, x, y, min, p, q);
            upd(x, (y >> i << i) + (1LL << i), x, y, min, p, q);
            upd((x>>i<<i) - 1, y >> i << i, x, y, min, p, q);
            upd(x >> i << i, (y >> i << i) - 1, x, y, min, p,q);
        }
    }
    cout << p << " " << q << "\n";
    
}

int main(int argc, char const *argv[]){
    int t;
    cin >> t;
    while (t--){
        solve();
        
    }
    
    return 0;
}