template<class T, int base>
class RollingHash{
    vector<long long> hash, power;
    static const int mod = 1000000007;
public:
    RollingHash(const T& s){
        init(s);
    }
    
    void init(const T& s){
        int n = s.size();
        hash.assign(n+1, 0);
        power.assign(n+1, 1);
        for(int i = 0; i < n; ++i){
            hash[i+1] = (hash[i] * base + s[i]) % mod;
            power[i+1] = power[i] * base % mod;
        }
    }
    
    //S[l, r)
    long long find(const int l, const int r){
        long long res = hash[r] + mod - hash[l] * power[r-l] % mod;
        if(res >= mod){
            res -= mod;
        }
        return res;
    }
};

template<class T>
vector<vector<long long>> rectangle_hash(const vector<T>& field, const int r, const int c){
    static const long long base1 = 1007, base2 = 2009;
    vector<RollingHash<T, base1>> rh;
    for(auto s : field){
        rh.emplace_back(s);
    }
    int h = field.size();
    int w = field[0].size();

    vector<vector<long long>> res(h-r+1, vector<long long>(w-c+1));

    for(int j = 0; j+c <= w; ++j){
        vector<long long> tmp(h);
        for(int i = 0; i < h; ++i){
            tmp[i] = rh[i].find(j, j+c);
        }

        RollingHash<vector<long long>, base2> second_step(tmp);
        for(int i = 0; i+r <= h; ++i){
            res[i][j] = second_step.find(i, i+r);
        }
    }
    return res;
}
