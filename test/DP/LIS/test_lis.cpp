/* 最長増加部分列
 *
 * AOJ DPL 1 D Longest Increasing Subsequence
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=ja
 */

#include <fstream>
#include <iostream>

#include "LIS.hpp"
#include "gtest/gtest.h"

using namespace std;

class TestLIS : public ::testing::TestWithParam<int> {
};

void LongestIncreasingSubsequence()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << lis(a) << endl;
}

TEST_P(TestLIS, LIS)
{
    int i = GetParam();

    stringstream in_file;
    in_file << "../../../../test/DP/LIS/test_data/input" << i << ".txt";
    ifstream in(in_file.str());
    ASSERT_FALSE(in.fail());
    cin.rdbuf(in.rdbuf());

    stringstream out_file;
    out_file << "../../../../test/DP/LIS/test_data/output" << i << ".txt";
    ifstream out(out_file.str());
    ASSERT_FALSE(out.fail());

    string result = string(istreambuf_iterator<char>(out), istreambuf_iterator<char>());

    testing::internal::CaptureStdout();
    LongestIncreasingSubsequence();
    ASSERT_STREQ(result.c_str(), testing::internal::GetCapturedStdout().c_str());
}

INSTANTIATE_TEST_SUITE_P(
    ParamtererizedTest,
    TestLIS,
    ::testing::Range(1, 11, 1)  // [1, 10)開区間
);