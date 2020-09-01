/* Union Find
 *
 * AOJ ALDS1 11 D Connected Components
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_D&lang=ja
 */

#include <fstream>
#include <iostream>

#include "UnionFind.hpp"
#include "gtest/gtest.h"

using namespace std;

class TestUnionFind : public ::testing::TestWithParam<int> {
};

void union_find()
{
    int n, m;
    cin >> n >> m;

    UnionFind uf(n);
    for (int i = 0; i < m; ++i) {
        int s, t;
        cin >> s >> t;
        uf.unite(s, t);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        if (uf.same(x, y)) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
}

TEST_P(TestUnionFind, UnionFind)
{
    int i = GetParam();

    stringstream in_file;
    in_file << "../../../../test/DataStructure/UnionFind/test_data/input" << i << ".txt";
    ifstream in(in_file.str());
    ASSERT_FALSE(in.fail());
    cin.rdbuf(in.rdbuf());

    stringstream out_file;
    out_file << "../../../../test/DataStructure/UnionFind/test_data/output" << i << ".txt";
    ifstream out(out_file.str());
    ASSERT_FALSE(out.fail());

    string result = string(istreambuf_iterator<char>(out), istreambuf_iterator<char>());

    testing::internal::CaptureStdout();
    union_find();
    ASSERT_STREQ(result.c_str(), testing::internal::GetCapturedStdout().c_str());
}

INSTANTIATE_TEST_SUITE_P(
    ParamtererizedTest,
    TestUnionFind,
    ::testing::Range(1, 11, 1)  // [1, 11)開区間
);