#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)

const int MAX = 1000; //ここは問題によって変える

//最長共通部分列問題
int lcs(string x, string y){
    
    int dp[MAX+1][MAX+1];
    int ret = 0;
    int n = x.size();
    int m = y.size();
    x = ' ' + x; //x[0]をつくる
    y = ' ' + y; //y[0]をつくる

    rep(i, n){
        dp[i][0] = 0;
    }
    rep(j, m){
        dp[0][j] = 0;
    } 
    
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(x[i] == y[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            ret = max(ret, dp[i][j]);
        }
    }
    return ret;
}