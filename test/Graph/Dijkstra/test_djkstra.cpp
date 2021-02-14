/**
 * Dijkstra
 *
 * よすぽさんのLibrary-Checker Shortest Path
 * https://judge.yosupo.jp/problem/shortest_path/
 */

#include <fstream>
#include <iostream>
#include <vector>

#include "dijkstra.hpp"
#include "gtest/gtest.h"

using namespace std;

class TestDjkstra : public ::testing::TestWithParam<int> {
};

void djkstra()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    Dijkstra dk(n);
    // 元々 0-index になっているので注意
    //     有向グラフになっているのも注意
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        dk.add(a, b, c);
    }

    dk.dijkstra(s);
    vector<int> path = dk.get_path(t);

    if (dk.dis[t] == INF) {
        cout << -1 << endl;
        return;
    }

    int len = path.size();
    cout << dk.dis[t] << " " << len - 1 << endl;
    for (int i = 0; i < len - 1; ++i) {
        //      from                to
        cout << path[i] << " " << path[i + 1] << endl;
    }
}

TEST_P(TestDjkstra, BellmanFord)
{
    int i = GetParam();

    stringstream in_file;
    in_file << "../../../../test/Graph/Dijkstra/test_data/input" << i << ".txt";
    ifstream in(in_file.str());
    ASSERT_FALSE(in.fail());
    cin.rdbuf(in.rdbuf());

    stringstream out_file;
    out_file << "../../../../test/Graph/Dijkstra/test_data/output" << i << ".txt";
    ifstream out(out_file.str());
    ASSERT_FALSE(out.fail());

    string result = string(istreambuf_iterator<char>(out), istreambuf_iterator<char>());

    testing::internal::CaptureStdout();
    djkstra();
    ASSERT_STREQ(result.c_str(), testing::internal::GetCapturedStdout().c_str());
}

INSTANTIATE_TEST_SUITE_P(
    ParamtererizedTest,
    TestDjkstra,
    ::testing::Range(1, 22, 1)  // [1, 21)開区間
);