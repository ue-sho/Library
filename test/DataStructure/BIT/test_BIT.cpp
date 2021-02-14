/**
 * Binary Indexed Tree
 *
 * AOJ Course DSL_2_B Range Query - Range Sum Query (RSQ)
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B&lang=jp
 */

#include <fstream>
#include <iostream>

#include "BIT.hpp"
#include "gtest/gtest.h"

using namespace std;

class TestBIT : public ::testing::TestWithParam<int> {
};

void binary_index_tree()
{
    int N, Q;
    cin >> N >> Q;
    BIT<int> bit(N);
    for (int query = 0; query < Q; ++query) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0)
            bit.add(x, y);
        else
            cout << bit.sum(x, y + 1) << endl;
    }
}

TEST_P(TestBIT, UnionFind)
{
    int i = GetParam();

    stringstream in_file;
    in_file << "../../../../test/DataStructure/BIT/test_data/input" << i << ".txt";
    ifstream in(in_file.str());
    ASSERT_FALSE(in.fail());
    cin.rdbuf(in.rdbuf());

    stringstream out_file;
    out_file << "../../../../test/DataStructure/BIT/test_data/output" << i << ".txt";
    ifstream out(out_file.str());
    ASSERT_FALSE(out.fail());

    string result = string(istreambuf_iterator<char>(out), istreambuf_iterator<char>());

    testing::internal::CaptureStdout();
    binary_index_tree();
    ASSERT_STREQ(result.c_str(), testing::internal::GetCapturedStdout().c_str());
}

INSTANTIATE_TEST_SUITE_P(
    ParamtererizedTest,
    TestBIT,
    ::testing::Range(1, 11, 1)  // [1, 11)開区間
);