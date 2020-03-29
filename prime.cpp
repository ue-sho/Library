class Prime{
public:
    int n;
    vector<int> factor, primes;    
    //エラストテネスの篩
    constexpr Prime(int n=100000) : n(n), factor(n+1){
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
    constexpr bool is_prime(int x){
        return factor[x] == x;
    }
    //約数列挙
    constexpr vector<int> factorList(int x){
        vector<int> ret;
        while(x != 1){
            ret.push_back(factor[x]);
            x /= factor[x];
        }
    }
    //素因数分解
    constexpr vector<P> factorize(int x){
        vector<int> fl = factorList(x);
        if(fl.size() == 0){
            return {};
        }
        vector<P> res(1, P(fl[0], 0));
        for (int p : fl) {
            if (res.back().first == p) {
                res.back().second++;
            }
            else {
                res.emplace_back(p, 1);
            }
        }
        return res;
    }
};