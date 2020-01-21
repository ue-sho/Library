
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
typedef long long ll;

const int MAX = 100000;
int d[MAX][MAX];

void warshall_floyd(int n) {
  for (int k = 0; k < n; k++){       // 経由する頂点
    for (int i = 0; i < n; i++) {    // 始点
      for (int j = 0; j < n; j++) {  // 終点
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

//d[i][j] 始点iから終点jまでの最短コストが入る。

int main() {

    //どの経路よりも大きい数字
    //たどり着けないことを表す
    constexpr int INF = 1e8;

    //頂点数
    int V;
    cin >> V;

    //辺の数
    int E;
    cin >> E;

    //隣接行列G
    //G[i][j]･･･頂点iから頂点jに行くまでの最短コスト
    vector<vector<int>> G(V, vector<int>(V, INF));

    //自分の頂点へは移動するコストは0なので0にする
    for (int i = 0; i < V; i++) {
        G[i][i] = 0;
    }

    //辺の入力
    for (int i = 0; i < E; i++) {
        int u, v, cost;
        cin >> u >> v >> cost, u--, v--;

        //頂点uからvへの辺のうち、一番小さいコストを使う
        G[u][v] = min(G[u][v], cost);

        //頂点vからuへの辺のうち、一番小さいコストを使う
        G[v][u] = min(G[v][u], cost);
    }

    //ワーシャルフロイド法
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }

    return 0;
}