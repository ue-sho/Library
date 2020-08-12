// クヌース・モリス・プラット法
// 単一パターン検索
//
// AOJ ALDS1 14 B String Search
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B

#include<iostream>
#include<vector>
using namespace std;

template<class T> 
class KMP{
    T pattern;
    vector<int> fail;
public:
    KMP(const T& p){ 
        init(p); 
    }
    
    void init(const T& p){
        pattern = p;
        int m = (int) pattern.size();
        fail.assign(m + 1, -1);
        for(int i = 0, j = -1; i < m; ++i){
            while(j >= 0 && pattern[i] != pattern[j]){
                j = fail[j];
            }
            // 一致しなかった時、次どこから始めるかを格納
            fail[i+1] = ++j;
        }
    }

    int period(int i) { return i - fail[i]; }
    
    vector<int> match(const T& S){
        int n = (int) S.size();
        int m = (int) pattern.size();
        vector<int> res;
        for(int i = 0, k = 0; i < n; ++i){
            while(k >= 0 && S[i] != pattern[k]){
                k = fail[k];
            }
            ++k;
            if(k >= m){
                // 一致したらSの始まりのidxを格納
                res.push_back(i - m + 1);
                k = fail[k];
            }
                
        }
        return res;
    }
};

int main() {

    string t, p;
    cin >> t >> p;

    KMP<string> kmp(p);

    vector<int> ans = kmp.match(t);

    for(auto x : ans){
        cout << x << endl;
    }

    return 0;
} 