
//尺取り法
int syakutori() {

    ll ans = 0;
    int right = 0;
    ll sum = 0;
    for (int left = 0; left < n; ++left) {
        while (right < n /* &&  sum * a[right] <= K (条件式)*/) {
            sum += a[right];
            ++right;
        }
        ans = max(ans, right - left); // 更新  //数え上げはこれ　ans += right - left;
        if (left == right){
            ++right;
        }
        else{
            sum -= a[left]; // left を除く ここはとりあえず左のやつをなかったことにする
        }
    }
    cout << ans << endl;

    return 0;
}