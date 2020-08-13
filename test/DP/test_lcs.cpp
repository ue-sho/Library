#include <iostream>

#include "gtest/gtest.h"
#include "lcs.hpp"

using namespace std;

/* 最長共通部分列
 *
 * AOJ ALDS1 10 C Longest Common Subsequence
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C&lang=ja
 */
void test_lcs()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        cout << lcs(s1, s2) << endl;
    }
}