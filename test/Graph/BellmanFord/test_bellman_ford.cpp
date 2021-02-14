/**
 * Bellman Ford
 *
 * AOJ GRL_1_B Single Source Shortest Path (Negative Edges)
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B&lang=ja
 */

#include <fstream>
#include <iostream>
#include <vector>

#include "bellman_ford.hpp"
#include "gtest/gtest.h"

using namespace std;

class TestBellmanFord : public ::testing::TestWithParam<int> {
};

void bellman_ford()
{
    int vertex, edge_num, start;
    cin >> vertex >> edge_num >> start;

    vector<Edge> edges;  //移動の情報を保存する
    for (int i = 0; i < edge_num; i++) {
        int from, to;
        long long cost;
        cin >> from >> to >> cost;
        edges.emplace_back(from, to, cost);
    }

    auto ans = BellmanFord(vertex, start, edges);
    if (ans.size() == 0) {
        cout << "NEGATIVE CYCLE" << endl;
        return;
    }

    for (auto x : ans) {
        if (x == INF) {
            cout << "INF" << endl;
            continue;
        }
        cout << x << endl;
    }
}

TEST_P(TestBellmanFord, BellmanFord)
{
    int i = GetParam();

    stringstream in_file;
    in_file << "../../../../test/Graph/BellmanFord/test_data/input" << i << ".txt";
    ifstream in(in_file.str());
    ASSERT_FALSE(in.fail());
    cin.rdbuf(in.rdbuf());

    stringstream out_file;
    out_file << "../../../../test/Graph/BellmanFord/test_data/output" << i << ".txt";
    ifstream out(out_file.str());
    ASSERT_FALSE(out.fail());

    string result = string(istreambuf_iterator<char>(out), istreambuf_iterator<char>());

    testing::internal::CaptureStdout();
    bellman_ford();
    ASSERT_STREQ(result.c_str(), testing::internal::GetCapturedStdout().c_str());
}

INSTANTIATE_TEST_SUITE_P(
    ParamtererizedTest,
    TestBellmanFord,
    ::testing::Range(1, 11, 1)  // [1, 10)開区間
);