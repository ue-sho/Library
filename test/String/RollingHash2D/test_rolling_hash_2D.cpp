/**
 * Rolling Hash 2D
 *
 * AOJ ALDS1 14 C Pattern Search
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C
 */

#include <fstream>
#include <iostream>
#include <vector>

#include "RollingHash2D.hpp"
#include "gtest/gtest.h"

using namespace std;

class TestRollingHash2D : public ::testing::TestWithParam<int> {
};

void rolling_hash_2D()
{
    int h, w;
    cin >> h >> w;
    vector<string> field(h);
    for (int i = 0; i < h; ++i) {
        cin >> field[i];
    }
    int r, c;
    cin >> r >> c;
    vector<string> pattern(r);
    for (int i = 0; i < r; ++i) {
        cin >> pattern[i];
    }

    auto feild_hash = rectangle_hash<string>(field, r, c);
    auto pattern_hash = rectangle_hash<string>(pattern, r, c);

    for (int i = 0; i + r <= h; ++i) {
        for (int j = 0; j + c <= w; ++j) {
            if (feild_hash[i][j] == pattern_hash[0][0]) {
                cout << i << " " << j << endl;
            }
        }
    }
}

TEST_P(TestRollingHash2D, RollingHash)
{
    int i = GetParam();

    stringstream in_file;
    in_file << "../../../../test/String/RollingHash2D/test_data/input" << i << ".txt";
    ifstream in(in_file.str());
    ASSERT_FALSE(in.fail());
    cin.rdbuf(in.rdbuf());

    stringstream out_file;
    out_file << "../../../../test/String/RollingHash2D/test_data/output" << i << ".txt";
    ifstream out(out_file.str());
    ASSERT_FALSE(out.fail());

    string result = string(istreambuf_iterator<char>(out), istreambuf_iterator<char>());

    testing::internal::CaptureStdout();
    rolling_hash_2D();
    ASSERT_STREQ(result.c_str(), testing::internal::GetCapturedStdout().c_str());
}

INSTANTIATE_TEST_SUITE_P(
    ParamtererizedTest,
    TestRollingHash2D,
    ::testing::Range(1, 11, 1)  // [1, 10)é–‹åŒºé–“
);