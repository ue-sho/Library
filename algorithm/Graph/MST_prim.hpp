// 最小全域木(minimum spanning tree)
// プリム法
// 重み付き連結グラフの最小全域木のコストを求める

#include <queue>
#include <vector>

using namespace std;

struct Edge {
    int destination;  //到達点
    int cost;         //移動コスト

    Edge() = default;
    Edge(int destination, int cost) : destination(destination), cost(cost) {}

    bool operator>(const Edge &edge) const
    {
        return cost > edge.cost;
    }
};

int Prim(const vector<vector<Edge>> &graph, int num_vertex)
{
    vector<bool> visited(num_vertex, false);  // 訪れたかどうかを記録する

    priority_queue<Edge, vector<Edge>, greater<Edge>> pri_queue;  // コストが小さい順に格納する
    pri_queue.emplace(0, 0);                                      // 初期値は 頂点 0 から始める（頂点 0 に行くまでのコストは 0）

    int total_cost = 0;  // 最小全域木のコストの総和
    while (!pri_queue.empty()) {
        Edge current_edge = pri_queue.top();
        pri_queue.pop();

        if (visited[current_edge.destination]) {
            continue;  // すでに訪問済み
        }

        visited[current_edge.destination] = true;
        total_cost += current_edge.cost;

        for (const Edge next_edge : graph[current_edge.destination]) {
            if (!visited[next_edge.destination]) {
                pri_queue.emplace(next_edge);
            }
        }
    }
    return total_cost;
}
