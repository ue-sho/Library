/**
 *  AOJ ALDS1_12_A Minimum Spanning Tree
 *  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A
 */

#include <fstream>
#include <iostream>
#include <vector>

#include "MST_prim.hpp"
#include "gtest/gtest.h"

using namespace std;

class TestMST_prim : public ::testing::TestWithParam<int> {
};

void MST_prim()
{
    int num_vertex = 0;
    cin >> num_vertex;

    vector<vector<prim::Edge>> graph;  // 隣接リストとして持つ
    constexpr int kNotAdjacent = -1;   // 隣接していないことを表す

    for (int i = 0; i < num_vertex; ++i) {
        for (int j = 0; j < num_vertex; ++j) {
            int cost;
            cin >> cost;
            if (cost != kNotAdjacent) {
                graph[i].emplace_back(j, cost);  // i から j に行くコスト
            }
        }
    }

    cout << prim::Prim(graph, num_vertex) << endl;
}

TEST_P(TestMST_prim, MSTprim)
{
    int i = GetParam();

    stringstream in_file;
    in_file << "../../../../test/Graph/MinimumSpanningTree/test_data/output" << i << ".txt";
    ifstream in(in_file.str());
    ASSERT_FALSE(in.fail());
    cin.rdbuf(in.rdbuf());

    stringstream out_file;
    out_file << "../../../../test/Graph/MinimumSpanningTree/test_data/output" << i << ".txt";
    ifstream out(out_file.str());
    ASSERT_FALSE(out.fail());

    string result = string(istreambuf_iterator<char>(out), istreambuf_iterator<char>());

    testing::internal::CaptureStdout();
    MST_prim();
    ASSERT_STREQ(result.c_str(), testing::internal::GetCapturedStdout().c_str());
}

INSTANTIATE_TEST_SUITE_P(
    ParamtererizedTest,
    TestMST_prim,
    ::testing::Range(1, 7, 1)  // [1, 6)開区間
);
