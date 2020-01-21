//二分探索 基本形

const ll MAX = 1000000000;
int binary_search(){
    
    ll a, b, x;
    cin >> a >> b >> x;

    ll left= 0, right = MAX, mid;
    while(right - left > 1){
        mid = (right + left) / 2;

        ll ans; /*  = a * mid + b * cnt;  */ //ここに計算式
        if(ans > x){
            right = mid;
        }
        else{
            left = mid;
        }
    }
    cout << left << endl;

    return 0;
}
