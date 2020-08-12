// 最長増加部分列

#include <iostream>

const int MAX = 100000;
int n, a[MAX];
int dp[MAX + 1];

int lis()
{
    dp[0] = a[0];
    int length = 1;

    for (int i = 1; i < n; ++i) {
        if (dp[length - 1] < a[i]) {
            dp[length++] = a[i];
        }
        else {
            *lower_bound(dp, dp + length, a[i]) = a[i];
        }
    }
    return length;
}
