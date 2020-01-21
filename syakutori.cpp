
/* 長さ nn の正の整数列 a1,a2,…,ana1,a2,…,an が与えられる。整数列の連続する部分列のうち、
 [ ~~~~~~ 」という条件を満たす最大長 (最小の長さ、数え上げ) を求めよ。 */

int syakutori() {

    int n;
    long long K;
    cin >> n >> K;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // O(n^2) を O(n) or O(nlogn)にする

    /* しゃくとり法 */
    int res = 0;
    int right = 0;
    long long mul = 1;
    for (int left = 0; left < n; ++left) {
        while (right < n /* &&  mul * a[right] <= K (条件式)*/) {
            mul *= a[right];
            ++right;
        }
        res = max(res, right - left); // 更新  //数え上げはこれ　ans += right - left;
        if (left == right) ++right;
        else mul /= a[left]; // left を除く ここはとりあえず左のやつをなかったことにする
    }

    cout << res << endl;

    return 0;
}