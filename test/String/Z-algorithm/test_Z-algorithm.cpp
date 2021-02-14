/**
 * Z algorithm
 *
 * ARC 060 F - ????
 * https://atcoder.jp/contests/arc060/tasks/arc060_d
 */

#include <fstream>
#include <iostream>

#include "Z-algorithm.hpp"
#include "gtest/gtest.h"

using namespace std;

class TestZalgo : public ::testing::TestWithParam<int> {
};

void Zalgorithm()
{
    string str;
    cin >> str;
    int n = (int)str.size();
    vector<long long> divs = divisor(n);
    long long syuuki = n;
    for (auto d : divs) {
        bool ok = true;
        for (int j = 0; j + d < n; ++j) {
            if (str[j] != str[j + d]) ok = false;
        }
        if (ok) syuuki = min(syuuki, d);
    }
    if (syuuki == n)
        cout << 1 << endl
             << 1 << endl;
    else if (syuuki == 1)
        cout << n << endl
             << 1 << endl;
    else {
        string str2 = str;
        reverse(str2.begin(), str2.end());
        auto lcp = Zalgo(str);
        auto lcp2 = Zalgo(str2);
        vector<int> cannot_cut(n * 2, 0);
        for (int d = 1; d < n; ++d) {
            if (cannot_cut[d]) continue;
            for (int dd = d * 2; dd < n; dd += d) {
                if (lcp[d] >= dd - d) cannot_cut[dd] = true;
                if (lcp2[d] >= dd - d) cannot_cut[n - dd] = true;
            }
        }
        int con = 0;
        for (int i = 1; i < n; ++i)
            if (!cannot_cut[i]) ++con;
        cout << 2 << endl
             << con << endl;
    }
}

TEST_P(TestZalgo, Zalgo)
{
    int i = GetParam();

    stringstream in_file;
    in_file << "../../../../test/String/Z-algorithm/test_data/input" << i << ".txt";
    ifstream in(in_file.str());
    ASSERT_FALSE(in.fail());
    cin.rdbuf(in.rdbuf());

    stringstream out_file;
    out_file << "../../../../test/String/Z-algorithm/test_data/output" << i << ".txt";
    ifstream out(out_file.str());
    ASSERT_FALSE(out.fail());

    string result = string(istreambuf_iterator<char>(out), istreambuf_iterator<char>());

    testing::internal::CaptureStdout();
    Zalgorithm();
    ASSERT_STREQ(result.c_str(), testing::internal::GetCapturedStdout().c_str());
}

INSTANTIATE_TEST_SUITE_P(
    ParamtererizedTest,
    TestZalgo,
    ::testing::Range(1, 11, 1)  // [1, 10)開区間
);