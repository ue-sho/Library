#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define REP(i, d, n) for(int i=(d); i<(n); i++)
typedef long long ll;
const int mod = 1e9 + 7;

//逆元　(割り算をmodしていきたいときに使用)
//modの世界では割り算に余りはない
ll mod_inv(ll a){
    
    ll b = mod, u = 1, v = 0;
    while(b){
        ll t = a / b;
        a -= t * b; 
        swap(a, b);
        u -= t * v; 
        swap(u, v);
    }
    u %= mod;
    if (u < 0){
        u += mod;
    } 
    return u;
}

// a ÷ b mod. MOD を計算してみる
int main() {

    long long a = 12345678900000;
    long long b = 100000;

    // a を 10000000007 で割ってから b の逆元をかけて計算
    a %= mod;
    cout << a * mod_inv(b) % mod << endl;
}