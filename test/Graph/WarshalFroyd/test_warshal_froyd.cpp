/**
 * Warshal Froyd
 *
 * AOJ GPL 1 C All Pairs Shortest Path
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=ja
 */

#include <fstream>
#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "warshal_froyd.hpp"

using namespace std;

class TestWarshalFroyd : public ::testing::TestWithParam<int> {
};

void warshal_froyd()
{
    int v, e;
    cin >> v >> e;
    vector<vector<long long>> cost(v, vector<long long>(v, INF));
    for (int i = 0; i < e; i++) {
        int s, t;
        long long d;
        cin >> s >> t >> d;
        cost[s][t] = d;
    }
    for (int i = 0; i < v; i++) {
        cost[i][i] = 0;
    }

    WarshalFroyd(cost, v);

    bool nega = false;
    for (int i = 0; i < v; i++) {
        if (cost[i][i] < 0) {
            nega = true;
        }
    }
    if (nega) {
        cout << "NEGATIVE CYCLE" << endl;
        return;
    }

    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (cost[i][j] == INF) {
                cout << "INF";
            }
            else {
                cout << cost[i][j];
            }
            if (j != v - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

TEST_P(TestWarshalFroyd, WarshalFroyd)
{
    int i = GetParam();

    stringstream in_file;
    in_file << "../../../../test/Graph/WarshalFroyd/test_data/input" << i << ".txt";
    ifstream in(in_file.str());
    ASSERT_FALSE(in.fail());
    cin.rdbuf(in.rdbuf());

    stringstream out_file;
    out_file << "../../../../test/Graph/WarshalFroyd/test_data/output" << i << ".txt";
    ifstream out(out_file.str());
    ASSERT_FALSE(out.fail());

    string result = string(istreambuf_iterator<char>(out), istreambuf_iterator<char>());

    testing::internal::CaptureStdout();
    warshal_froyd();
    ASSERT_STREQ(result.c_str(), testing::internal::GetCapturedStdout().c_str());
}

INSTANTIATE_TEST_SUITE_P(
    ParamtererizedTest,
    TestWarshalFroyd,
    ::testing::Range(1, 11, 1)  // [1, 10)開区間
);