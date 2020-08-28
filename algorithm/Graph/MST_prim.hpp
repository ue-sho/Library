// 最小全域木(minimum spanning tree)
// プリム法

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using P = pair<int, int>;

namespace prim {

struct Edge {
    int destination_;  //到達点
    int cost_;         //移動コスト

    Edge(int destination, int cost) : destination_(destination), cost_(cost) {}

    bool operator>(const Edge &edge) const
    {
        return cost_ > edge.cost_;
    }
};

// プリム法
// 重み付き連結グラフの最小全域木のコストを求める
int Prim(const vector<vector<Edge>> &graph, const int num_vertex)
{
    vector<bool> visited(num_vertex, false);  // 訪れたかどうかを記録する

    priority_queue<Edge, vector<Edge>, greater<Edge>> pri_queue;  // コストが小さい順に格納する
    pri_queue.emplace(0, 0);                                      // 初期値は 頂点 0 から始める（頂点 0 に行くまでのコストは 0）

    int total_cost = 0;  // 最小全域木のコストの総和
    while (!pri_queue.empty()) {
        Edge current_edge = pri_queue.top();
        pri_queue.pop();

        if (visited[current_edge.destination_]) {
            continue;  // すでに訪問済み
        }

        visited[current_edge.destination_] = true;
        total_cost += current_edge.cost_;

        for (const Edge next_edge : graph[current_edge.destination_]) {
            if (!visited[next_edge.destination_]) {
                pri_queue.emplace(next_edge);
            }
        }
    }
    return total_cost;
}

}  // namespace prim