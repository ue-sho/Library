#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define REP(i, d, n) for(int i=(d); i<(n); i++)
typedef long long ll;
const int mod = 1e9 + 7;

//modありのべき乗　xのn乗
ll mod_pow(ll x, ll n){

    ll ret = 1;
    while(n > 0){
        if(n & 1){
            (ret *= x) %= mod;
        }
        (x *= x) %= mod;
        n >>= 1;
    }
    return ret;
}