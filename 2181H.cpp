#include<bits/stdc++.h>
#include <iostream>


using namespace std;


int main(int argc, char const *argv[])
{
    long long w, h, d;
    cin >> w >> h >> d;
    long long n;
    cin >> n;
    w = w % n;
    h = h  % n;
    d = d % n;
    if (w * h * d % n != 0) cout << "-1" << endl;
    else {
        int wp = gcd(n, w);
        n = n / wp;
        int hp = gcd(n, h);
        n = n / hp;
        int dp = gcd(n, d);
        n = n / dp;
        if (n == 1) cout << wp - 1 << " " << hp - 1 << " " << dp - 1 << endl;
        else cout << "-1" << endl;
    } 
    return 0;
    
   
}
