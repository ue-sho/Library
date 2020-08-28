/**
 *  AOJ ALDS1_14_B String Search
 *  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
 */

#include <fstream>
#include <iostream>

#include "KMP.hpp"
#include "gtest/gtest.h"

using namespace std;

class TestKMP : public ::testing::TestWithParam<int> {
};

void StringSearch()
{
    string text, pattern;
    cin >> text >> pattern;

    KMP<string> kmp(pattern);

    vector<int> ans = kmp.Match(text);

    for (auto x : ans) {
        cout << x << '\n';
    }
}

TEST_P(TestKMP, KMP)
{
    int i = GetParam();

    stringstream in_file;
    in_file << "../../../../test/String/KMP/test_data/input" << i << ".txt";
    ifstream in(in_file.str());
    ASSERT_FALSE(in.fail());
    cin.rdbuf(in.rdbuf());

    stringstream out_file;
    out_file << "../../../../test/String/KMP/test_data/output" << i << ".txt";
    ifstream out(out_file.str());
    ASSERT_FALSE(out.fail());

    string result = string(istreambuf_iterator<char>(out), istreambuf_iterator<char>());

    testing::internal::CaptureStdout();
    StringSearch();
    ASSERT_STREQ(result.c_str(), testing::internal::GetCapturedStdout().c_str());
}

INSTANTIATE_TEST_SUITE_P(
    ParamtererizedTest,
    TestKMP,
    ::testing::Range(1, 11, 1)  // [1, 11)開区間
);
