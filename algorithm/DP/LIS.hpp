// 最長増加部分列
#include <iostream>
#include <vector>
using namespace std;

int lis(const vector<int> &a)
{
    int n = a.size();
    vector<int> dp(n + 1);
    dp[0] = a[0];
    int length = 1;

    for (int i = 1; i < n; ++i) {
        if (dp[length - 1] < a[i]) {
            dp[length++] = a[i];
        }
        else {
            *lower_bound(dp.begin(), dp.begin() + length, a[i]) = a[i];
        }
    }
    return length;
}
