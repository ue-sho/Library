// ワーシャルフロイド(warshall_floyd) 計算量 O( N^3 )
//
// AOJ GPL 1 C All Pairs Shortest Path
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=ja

#include<iostream>
#include<vector>
using namespace std;

void warshall_floyd(int n) {
    
    for(int k = 0; k < n; k++){           // 経由する頂点
        for(int i = 0; i < n; i++) {      // 始点
            for(int j = 0; j < n; j++) {  // 終点
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {

    int v, e;
    cin >> v >> e;
    const long long INF = 1LL << 60;
    vector<vector<long long> > cost(v, vector<long long>(v, INF));
    for(int i = 0; i < e; i++){
        int s, t, d;
        cin >> s >> t >> d;
        cost[s][t] = d;
    }
    for(int i = 0; i < v; i++){
        cost[i][i] = 0;
    }

    // -----------------------------------------------------------------------

    for(int k = 0; k < v; k++){          // 経由する頂点
        for(int i = 0; i < v; i++){      // 始点
            for(int j = 0; j < v; j++){  // 終点
                if(cost[i][k] != INF && cost[k][j] != INF){
                    cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
                }
            }
        }
    }
    // -----------------------------------------------------------------------
    
    bool nega = false;
    for(int i = 0; i < v; i++){
        if(cost[i][i] < 0){
            nega = true;
        }
    }
    if(nega){
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    
    for(int i = 0; i < v; i++){
        for(int j = 0; j < v; j++){
            if(cost[i][j] == INF){
                cout << "INF";
            }
            else{
                cout << cost[i][j];
            }
            if(j != v-1){
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}