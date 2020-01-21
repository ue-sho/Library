#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define REP(i, d, n) for(int i=(d); i<(n); i++)
typedef long long ll;
const int mod = 1e9 + 7;

//最大公約数
template <class T>
T gcd(T a, T b) {

    if(b == 0){
        return a;
    }
    else{
        gcd(b, a%b);
    }
}

//最小公倍数
template <class T>
T lcm(T a, T b){

    T g = gcd(a, b);

    return a / g * b; //これだとintでオーバーフローしない
                    // (a * b) / g
}