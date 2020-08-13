// 最長共通部分列
#include <iostream>
#include <vector>

int lcs(std::string x, std::string y)
{
    const int MAX = 1000;
    std::vector<std::vector<int>> dp(MAX + 1, std::vector<int>(MAX + 1));

    int cnt = 0;
    int n = x.length();
    int m = y.length();
    // 1-indexにする
    x = ' ' + x;  // x[0]をつくる
    y = ' ' + y;  // y[0]をつくる

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (x[i] == y[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
            cnt = std::max(cnt, dp[i][j]);
        }
    }
    return cnt;
}