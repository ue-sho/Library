#include<iostream>
#include<vector>

using namespace std;

class Prime{
public:
    int n;
    vector<int> f, primes;
  
    // エラストテネスの篩
    Prime(int n = 1) : n(n), f(n+1) {
        f[0] = f[1] = -1;
        for(int i = 2; i <= n; ++i){
            if(f[i]){
                continue;
            }
            primes.push_back(i);
            f[i] = i;
            for(int j = i*i; j <= n; j += i){
                if(!f[j]){
                    f[j] = i;
                }
            }
        }
    }

    // 素数判定
    bool isPrime(int x){ 
        return f[x] == x;
    }
    
    // 約数列挙
    vector<int> factorList(int x){
        vector<int> res;
        while(x != 1){
            res.push_back(f[x]);
            x /= f[x];
        }
        return res;
    }

    // 素因数分解　（xがnより小さい版）
    vector<pair<int, int>> factor1(int x){
        vector<int> fl = factorList(x);
        if(fl.size() == 0){
            return {};
        }
        vector<pair<int, int>> res(1, pair<int, int>(fl[0], 0));
        for(int p : fl){
            if(res.back().first == p){
                res.back().second++;
            } 
            else{
                res.emplace_back(p, 1);
            }
        }
        return res;
    }

    // 素因数分解　（xがnより大きい版）
    vector<pair<int,int>> factor2(int x){
        vector<pair<int,int>> res;
        for(int p : primes){
            int y = 0;
            while(x % p == 0){
                x /= p;
                ++y;
            }
            if(y != 0){
                res.emplace_back(p, y);
            }
        }
        if(x != 1){
            res.emplace_back(x, 1);
        }
        return res;
    }
};