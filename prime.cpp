#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
#define REP(i, d, n) for(int i=(d); i<(n); i++)
using ll = long long;
using P = pair<int, int>;

//素数判定
bool is_prime(int x){

    for(int i = 2; i * i <= x; ++i) {
        if(x % i == 0){
            return false;
        }
    }
    return true;
}

// 素因数分解
// pairのfirstに素因数　secondに素因数の数
template <class T>
vector<pair<T, int>> factorize(T num){

    vector<pair<T, int>> res;
    for(T i = 2; i * i <= num; ++i){
        if(num % i){  //割り切れないなら素因数ではない
            continue;
        }
        res.emplace_back(i, 0);
        while(num % i == 0){
            res.back().second++;
            num /= i;
        }
    }
    if(num != 1){
        res.emplace_back(num, 1);
    }
    return res;
}

class Prime{
    int n;
    vector<int> factor, primes;    
public:
    Prime(int n=1) : n(n), factor(n+1){
        factor[0] = factor[1] = -1;
        for(ll i=2; i <= n; ++i){
            if(factor[i]) continue;
            primes.push_back(i);
            factor[i] = i;
            for(ll j = i*i; j <= n; j += i){
                if(!factor[j]) factor[j] = i;
            }
        }
    }

    bool is_prime(int x){
        return factor[x] == x;
    }

    vector<int> factorList(int x){
        vector<int> ret;
        while(x != 1){
            ret.push_back(factor[x]);
            x /= factor[x];
        }
    }

    vector<P> factorize(int x){
        vector<int> fl = factorList(x);
        if(fl.size() == 0){
            return {};
        }
        vector<P> ret(1, P());
        return ret;
    }
};