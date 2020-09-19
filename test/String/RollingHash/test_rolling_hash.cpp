/**
 * Rolling Hash
 *
 * ABC 141 E - Who Says a Pun?
 * https://atcoder.jp/contests/abc141/tasks/abc141_e
 */

#include <fstream>
#include <iostream>
#include <vector>

#include "RollingHash.hpp"
#include "gtest/gtest.h"

using namespace std;

class TestRollingHash : public ::testing::TestWithParam<int> {
};

void rolling_hash()
{
    int N;
    string S;
    cin >> N >> S;

    RollingHash rh(S);

    int res = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int lcp = rh.getLCP(i, j);
            lcp = min(lcp, j - i);
            res = max(res, lcp);
        }
    }
    cout << res << endl;
}

TEST_P(TestRollingHash, RollingHash)
{
    int i = GetParam();

    stringstream in_file;
    in_file << "../../../../test/String/RollingHash/test_data/input" << i << ".txt";
    ifstream in(in_file.str());
    ASSERT_FALSE(in.fail());
    cin.rdbuf(in.rdbuf());

    stringstream out_file;
    out_file << "../../../../test/String/RollingHash/test_data/output" << i << ".txt";
    ifstream out(out_file.str());
    ASSERT_FALSE(out.fail());

    string result = string(istreambuf_iterator<char>(out), istreambuf_iterator<char>());

    testing::internal::CaptureStdout();
    rolling_hash();
    ASSERT_STREQ(result.c_str(), testing::internal::GetCapturedStdout().c_str());
}

INSTANTIATE_TEST_SUITE_P(
    ParamtererizedTest,
    TestRollingHash,
    ::testing::Range(1, 11, 1)  // [1, 10)開区間
);