// 最小全域木(minimum spanning tree)
// クラスカル法

#include <algorithm>
#include <vector>

using namespace std;

class UnionFind {
public:
    vector<int> d;

    UnionFind(int n = 0) : d(n, -1) {}

    int find(int x)
    {
        if (d[x] < 0) {
            return x;
        }
        return d[x] = find(d[x]);  // メモ化再帰
    }

    bool unite(int x, int y)
    {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (size(x) < size(y)) {
            swap(x, y);
        }
        d[x] += d[y];
        d[y] = x;
        return true;
    }

    bool same(int x, int y)
    {
        return find(x) == find(y);
    }

    int size(int x)
    {
        return -d[find(x)];
    }
};  // namespace UnionFind

class Edge {
public:
    int from, to;
    int cost;

    Edge(int from, int to, int cost)
        : from(from), to(to), cost(cost) {}

    // コストの大小で順序定義
    bool operator<(const Edge& o) const
    {
        return cost < o.cost;
    }
};

// クラスカル法で無向最小全域木のコストの和を計算する
// グラフが非連結のときは最小全域森のコストの和となる
int Kruskal(vector<Edge>& edges, int n)
{
    // コストが小さい順にソート
    sort(edges.begin(), edges.end());

    UnionFind uf(n);
    int min_cost = 0;
    for (const Edge e : edges) {
        if (!uf.same(e.from, e.to)) {
            // 辺を追加しても閉路ができないなら、その辺を採用する
            min_cost += e.cost;
            uf.unite(e.from, e.to);
        }
    }
    return min_cost;
}
