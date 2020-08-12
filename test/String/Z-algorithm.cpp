// Z-algorithm
//   res[i] := S[i:] と S[0: ] との最長共通部分列の長さ
//
// けんちょんさんの引用　(https://github.com/drken1215/algorithm/blob/master/String/z_algorithm.cpp)
//
// ARC 060 F - 最良表現
// https://atcoder.jp/contests/arc060/tasks/arc060_d

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> Zalgo(const string &S) {
    int N = (int)S.size();
    vector<int> res(N);
    res[0] = N;
    int i = 1, j = 0;
    while (i < N) {
        while (i+j < N && S[j] == S[i+j]) ++j;
        res[i] = j;
        if (j == 0) {++i; continue;}
        int k = 1;
        while (i+k < N && k+res[k] < j) res[i+k] = res[k], ++k;
        i += k, j -= k;
    }
    return res;
}

vector<long long> divisor(long long n) {
    vector<long long> res;
    for (long long i = 1LL; i*i <= n; ++i) {
        if (n%i == 0LL) {
            res.push_back(i);
            long long temp = n/i;
            if (i != temp) res.push_back(temp);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    string str; cin >> str;
    int n = (int)str.size();
    vector<long long> divs = divisor(n);
    long long syuuki = n;
    for (auto d : divs) {
        bool ok = true;
        for (int j = 0; j + d < n; ++j) {
            if (str[j] != str[j+d]) ok = false;
        }
        if (ok) syuuki = min(syuuki, d);
    }
    if (syuuki == n) cout << 1 << endl << 1 << endl;
    else if (syuuki == 1) cout << n << endl << 1 << endl;
    else {
        string str2 = str;
        reverse(str2.begin(), str2.end());
        auto lcp = Zalgo(str);
        auto lcp2 = Zalgo(str2);
        vector<int> cannot_cut(n*2, 0);
        for (int d = 1; d < n; ++d) {
            if (cannot_cut[d]) continue;
            for (int dd = d*2; dd < n; dd += d) {
                if (lcp[d] >= dd - d) cannot_cut[dd] = true;
                if (lcp2[d] >= dd - d) cannot_cut[n-dd] = true;
            }
        }
        int con = 0;
        for (int i = 1; i < n; ++i) if (!cannot_cut[i]) ++con;
        cout << 2 << endl << con << endl;
    }
}