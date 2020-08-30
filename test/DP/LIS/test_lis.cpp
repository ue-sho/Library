#include "gtest/gtest.h"
#include "lis.hpp"

using namespace std;

/* 最長増加部分列
 *
 * AOJ DPL 1 D Longest Increasing Subsequence
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=ja
 */
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