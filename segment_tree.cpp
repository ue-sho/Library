#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
typedef long long ll;

const int SEG_LEN = 1 << 17; //131072 (10の5乗より大きい2進数)

int seg[SEG_LEN * 2];

//1点　加算
void seg_add(int idx, int v){
    idx += SEG_LEN;
    seg[idx] += v;
    while(true){
        idx /= 2;
        if(idx == 0){
            break;
        }
        seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
    }
}

//区間　和
int seg_sum(int r, int l){
    l += SEG_LEN;
    r += SEG_LEN;

    int ret = 0;
    while(l < r){
        if(l % 2 == 1){
            ret += seg[l++];
        }
        l /= 2;

        if(r % 2 == 1){
            ret += seg[--r];
        }
        r /= 2;
    }
    return ret;
}