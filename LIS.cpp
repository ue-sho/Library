#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
typedef long long ll;
const int mod = 1e9 + 7;

const int MAX = 100000;
int n, a[MAX];
int dp[MAX+1];

//最長増加部分列問題
int lis(){
    dp[0] = a[0];
    int length = 1;

    REP(i, 1, n){
        if(dp[length-1] < a[i]){
            dp[length++] = a[i];
        }
        else{
            *lower_bound(dp, dp+length, a[i]) = a[i];
        }
    }
    return length;
}

int main() {

    cin >> n;
    rep(i, n){
        cin >> a[i];
    }
    
    int ans = lis();
    cout << ans << endl;

    return 0;
}