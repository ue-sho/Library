// SuffixArray　部分文字列が何個あるか分かる
//
// AOJ ALDS1 14 D Multiple String Matching
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class SuffixArray{
    string s;
    vector<int> sort_idx, rev;
public:
    // 接尾辞配列を作る
    SuffixArray(const string &str) : s(str) {
        int n = s.size();
        s.push_back('$');
        sort_idx.resize(n+1);
        iota(sort_idx.begin(), sort_idx.end(), 0);
        // 辞書順に並び変えたときのインデックス記録
        sort(sort_idx.begin(), sort_idx.end(),
            [&](int a,int b){
                if(s[a] == s[b]){
                    return a > b;
                }
                return s[a] < s[b];
            });
        vector<int> c(n+1), r(n+1), cnt(n+1);
        for(int i = 0; i <= n; i++){
            r[i] = s[i];
        }
        for(int len = 1; len <= n; len *= 2){
            for(int i = 0; i <= n; ++i){
                c[sort_idx[i]] = i;
                if(i > 0 && r[sort_idx[i-1]] ==r[sort_idx[i]] 
                    && sort_idx[i-1] + len <= n 
                    && r[sort_idx[i-1]+len/2] == r[sort_idx[i]+len/2]){
                    
                    c[sort_idx[i]]=c[sort_idx[i-1]];
                }
            }
            iota(cnt.begin(), cnt.end(), 0);
            copy(sort_idx.begin(), sort_idx.end(), r.begin());
            for(int i = 0; i <= n; ++i){
                int s1 = r[i] - len;
                if(s1 >= 0){
                    sort_idx[cnt[c[s1]]++]=s1;
                }
            }
            c.swap(r);
        }
        rev.resize(n+1);
        for(int i = 0; i <= n; ++i){
            rev[sort_idx[i]] = i;
        }
    }

    int operator[](int i) const { return sort_idx[i]; }

    // s の中に t があるかどうか
    bool find(string &t, int s_idx, int t_idx){
        int s_len = s.size();
        int t_len = t.size();
        while(s_idx < s_len && t_idx < t_len){
            if(s[s_idx] < t[t_idx]){
                return true;
            }
            if(s[s_idx] > t[t_idx]){
                return false;
            }
            s_idx++; t_idx++;
        }
        return s_idx == s_len && t_idx < t_len;
    }

    int lower_bound(string& t){
        int left = 0;
        int right = s.size();
        while(left+1 < right){
            int mid = (left + right) >> 1;
            if(find(t, sort_idx[mid], 0)){
                left = mid;
            }
            else{
                right = mid;
            }
        }
        return right;
    }

    int upper_bound(string& t){
        t.back()++;
        int res = lower_bound(t);
        t.back()--;
        return res;
    }

    int count(string& T){
        return upper_bound(T) - lower_bound(T);
    }
};


int main(){
    
    string t;
    int q;
    cin >> t >> q;
    
    SuffixArray sort_idx(t);
    for(int i = 0; i < q; ++i){
        string p;
        cin >> p;
        if(sort_idx.count(p) > 0){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    return 0;
}