#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
typedef long long ll;

//約数列挙
vector<int> divisor(int n){

    vector<int> ret;
    for(int i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n){
                ret.push_back(n / i);
            } 
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}