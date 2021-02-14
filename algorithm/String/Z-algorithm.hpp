// Z-algorithm res[i] := S[i:] と S[0: ] との最長共通部分列の長さ
// けんちょんさんの引用　(https://github.com/drken1215/algorithm/blob/master/String/z_algorithm.cpp)

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> Zalgo(const string &S)
{
    int N = (int)S.size();
    vector<int> res(N);
    res[0] = N;
    int i = 1, j = 0;
    while (i < N) {
        while (i + j < N && S[j] == S[i + j]) {
            ++j;
        }
        res[i] = j;
        if (j == 0) {
            ++i;
            continue;
        }
        int k = 1;
        while (i + k < N && k + res[k] < j) {
            res[i + k] = res[k], ++k;
        }
        i += k;
        j -= k;
    }
    return res;
}

vector<long long> divisor(long long n)
{
    vector<long long> res;
    for (long long i = 1LL; i * i <= n; ++i) {
        if (n % i == 0LL) {
            res.push_back(i);
            long long temp = n / i;
            if (i != temp) res.push_back(temp);
        }
    }
    sort(res.begin(), res.end());
    return res;
}
