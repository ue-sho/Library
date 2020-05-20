// nCr 組み合わせ
// 前処理　計算量 O(log n)
// 計算量　O(1)
constexpr int mod = 1e9+7;
class Combination {
public:
    vector<int> fac, finv, inv;
    Combination(int n) : fac(n), finv(n), inv(n) {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < n; ++i){
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = mod - inv[mod%i] * (mod / i) % mod;
            finv[i] = finv[i - 1] * inv[i] % mod;
        }
    }
    int calc(int n, int k){
        if (n < k){
            return 0;
        }
        if (n < 0 || k < 0){
            return 0;
        } 
        return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
    }
};

//重複なし組み合わせ　nHk = (n+k-1)C(n-1)