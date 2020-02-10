// nCr 組み合わせ

const int MAX = 1e5+1; //ここは問題によって変える
const int mod = 1e9+7
//  n!  *   (k!)^-1  *  ((n-k)!)^-1
ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
// 計算量　O(n)
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; ++i){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

// 二項係数計算 nCk
// 計算量　O(1)
ll Combination(int n, int k){
    if (n < k){
        return 0;
    }
    if (n < 0 || k < 0){
        return 0;
    } 
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}


