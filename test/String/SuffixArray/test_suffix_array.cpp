/**
 * Suffix Array
 *
 * AOJ ALDS1 14 D Multiple String Matching
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D
 */

#include <fstream>
#include <iostream>
#include <vector>

#include "SuffixArray.hpp"
#include "gtest/gtest.h"

using namespace std;

class TestSuffixArray : public ::testing::TestWithParam<int> {
};

void suffix_array()
{
    string t;
    int q;
    cin >> t >> q;

    SuffixArray sort_idx(t);
    for (int i = 0; i < q; ++i) {
        string p;
        cin >> p;
        if (sort_idx.count(p) > 0) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
}

TEST_P(TestSuffixArray, RollingHash)
{
    int i = GetParam();

    stringstream in_file;
    in_file << "../../../../test/String/SuffixArray/test_data/input" << i << ".txt";
    ifstream in(in_file.str());
    ASSERT_FALSE(in.fail());
    cin.rdbuf(in.rdbuf());

    stringstream out_file;
    out_file << "../../../../test/String/SuffixArray/test_data/output" << i << ".txt";
    ifstream out(out_file.str());
    ASSERT_FALSE(out.fail());

    string result = string(istreambuf_iterator<char>(out), istreambuf_iterator<char>());

    testing::internal::CaptureStdout();
    suffix_array();
    ASSERT_STREQ(result.c_str(), testing::internal::GetCapturedStdout().c_str());
}

INSTANTIATE_TEST_SUITE_P(
    ParamtererizedTest,
    TestSuffixArray,
    ::testing::Range(1, 11, 1)  // [1, 10)開区間
);