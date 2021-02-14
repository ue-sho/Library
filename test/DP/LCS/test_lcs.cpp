/**
 * 最長共通部分列
 *
 * AOJ ALDS1 10 C Longest Common Subsequence
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C&lang=ja
 */

#include <fstream>
#include <iostream>

#include "LCS.hpp"
#include "gtest/gtest.h"

using namespace std;

class TestLCS : public ::testing::TestWithParam<int> {
};

void LongestCommonSubsequence()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << lcs(s1, s2) << endl;
    }
}

TEST_P(TestLCS, LCS)
{
    int i = GetParam();

    stringstream in_file;
    in_file << "../../../../test/DP/LCS/test_data/input" << i << ".txt";
    ifstream in(in_file.str());
    ASSERT_FALSE(in.fail());
    cin.rdbuf(in.rdbuf());

    stringstream out_file;
    out_file << "../../../../test/DP/LCS/test_data/output" << i << ".txt";
    ifstream out(out_file.str());
    ASSERT_FALSE(out.fail());

    string result = string(istreambuf_iterator<char>(out), istreambuf_iterator<char>());

    testing::internal::CaptureStdout();
    LongestCommonSubsequence();
    ASSERT_STREQ(result.c_str(), testing::internal::GetCapturedStdout().c_str());
}

INSTANTIATE_TEST_SUITE_P(
    ParamtererizedTest,
    TestLCS,
    ::testing::Range(1, 6, 1)  // [1, 5)開区間
);