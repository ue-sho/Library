// ベルマンフォード(bellman_ford)   計算量：O(|E||V|)
// 負のコストがあっても最短経路出せる
#include<iostream>
#include<vector>
using namespace std;

constexpr long long INF = 1LL << 60;

struct edge {
    int from; //出発点
    int to;   //到達点
    long long cost; //移動コスト
    edge(int from, int to, long long cost) 
        : from(from), to(to), cost(cost) {}
};

int main(){
    int V;      //頂点の数
    int side;   //辺の数
    int S;      //始点
    int G;      //終点
    cin >> V >> side >> S >> G;

    vector<edge> edges;     //移動の情報を保存する
    for(int i = 0; i < side; i++){
        int from, to;
        long long cost;
        cin >> from >> to >> cost
        edges.emplace_back(from, to, cost);
    }

    vector<long long> dis(V, INF);  //始点からそこまで行くのにかかるコスト
    dis[S] = 0;                     //始点を0にする
    for(int i = 0; i < V; ++i){
        for(const edge e : edges){
            if(dis[e.from] != INF && dis[e.to] > dis[e.from] + e.cost){  //移動した後のコストが小さいと、頂点のコストを更新
                dis[e.to] = dis[e.from] + e.cost;
                // ここが重要！
                if(i == V-1) {         //頂点の数と同じ回数ループすると、負の閉路があるのでループをぬける
                    cout << "negative loop" << endl;
                    break;
                } 
            }
        }
    }

    cout << "\n頂点" << S << "から頂点" << G << "まで移動するのにかかるコストの最小は" << dis[G] << endl;
}