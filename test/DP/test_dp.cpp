#include <iostream>

#include "gtest/gtest.h"
#include "lcs.hpp"
#include "lis.hpp"

using namespace std;

/* 最長共通部分列
 *
 * AOJ ALDS1 10 C Longest Common Subsequence
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C&lang=ja
 */
void test_lcs()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << lcs(s1, s2) << endl;
    }
}
/* 最長増加部分列
 *
 * AOJ DPL 1 D Longest Increasing Subsequence
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=ja
 */
const int MAX = 100000;
int n, a[MAX];
int dp[MAX + 1];

int test_lis()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int ans = lis();
    cout << ans << endl;

    return 0;
}

TEST(addTest, Negative)
{
    EXPECT_EQ(-5, add(-2, -3));
    EXPECT_EQ(-1, add(-1, 0));
}

TEST(addTest, Zero)
{
    EXPECT_EQ(0, add(-2, 2));
}

TEST(addTest, Positive)
{
    EXPECT_EQ(1, add(1, 0));
    EXPECT_EQ(2, add(1, 1));
    EXPECT_EQ(120, add(55, 65));
}