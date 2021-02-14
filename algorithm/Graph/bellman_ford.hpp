// ベルマンフォード(bellman_ford)   計算量：O(|E||V|)
// 負のコストがあっても最短経路出せる

#include <vector>

using namespace std;

constexpr long long INF = 1LL << 60;

struct Edge {
    int from;        //出発点
    int to;          //到達点
    long long cost;  //移動コスト
    Edge() = default;
    Edge(int from, int to, long long cost)
        : from(from), to(to), cost(cost) {}
};

vector<long long> BellmanFord(int vertex, int start, vector<Edge> &edges)
{
    vector<long long> dis(vertex, INF);  //始点からそこまで行くのにかかるコスト
    dis[start] = 0;                      //始点を0にする
    for (int i = 0; i < vertex; ++i) {
        for (const Edge e : edges) {
            if (dis[e.from] != INF && dis[e.to] > dis[e.from] + e.cost) {  //移動した後のコストが小さいと、頂点のコストを更新
                dis[e.to] = dis[e.from] + e.cost;
                if (i == vertex - 1) {  //頂点の数と同じ回数ループすると、負の閉路があるのでループをぬける
                    return {};
                }
            }
        }
    }
    return dis;
}
