#include <fstream>
#include <iostream>

#include "gtest/gtest.h"
#include "kmp.h"

using namespace std;

class MultipleTest : public ::testing::TestWithParam<int> {
};

int StringSearch()
{
    string text, pattern;
    cin >> text >> pattern;

    KMP<string> kmp(p);

    vector<int> ans = kmp.Match(t);

    for (auto x : ans) {
        cout << x << endl;
    }
}

TEST_P(TestString, KMP)
{
    int i = GetParam();

    stringstream in_file;
    in_file << "kmp_test_data/input" << i << ".txt";
    ifstream in(in_file.str());
    ASSERT_FALSE(in.fail());
    cin.rdbuf(in.rdbuf());

    stringstream out_file;
    out_file << "kmp_test_data/output" << i << ".txt";
    ifstream out(out_file.str());
    ASSERT_FALSE(out.fail());

    string result = string(istreambuf_iterator<char>(out), istreambuf_iterator<char>());

    testing::internal::CaptureStdout();
    StringSearch();
    ASSERT_STREQ(result.c_str(), testing::internal::GetCapturedStdout().c_str());
}

INSTANTIATE_TEST_SUITE_P(
    ParamtererizedTest,
    MultipleTest,
    ::testing::Range(1, 11, 1)  // [1, 11)半開区間
);
