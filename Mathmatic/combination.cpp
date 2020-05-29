// nCr 組み合わせ
// 前処理　計算量 O(log n)
// 計算量　O(1)
//
// ABC021 D 多重ループ
// https://atcoder.jp/contests/abc021/tasks/abc021_d

#include<iostream>
#include<vector>
using namespace std;

constexpr int mod = 1e9+7;
class Combination {
public:
    vector<long long> fac, finv, inv;
    Combination(int n = 100000) : fac(n+1), finv(n+1), inv(n+1) {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i <= n; ++i){
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = mod - inv[mod%i] * (mod / i) % mod;
            finv[i] = finv[i - 1] * inv[i] % mod;
        }
    }

    long lnog calc(int n, int k){
        if (n < k){
            return 0;
        }
        if (n < 0 || k < 0){
            return 0;
        } 
        return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
    }
};

int main() {

    int n, k;
    cin >> n >> k;

    Combination com(200000);

    // 重複組み合わせ
    // n 種類あるから (n-1)本の仕切りを用意
    // k個 と (n-1)本の仕切りを並べる
    // その中から、仕切りの場所 (n-1) を選ぶ
    cout << com.calc(n-1+k, n-1) << endl;

    return 0;
}