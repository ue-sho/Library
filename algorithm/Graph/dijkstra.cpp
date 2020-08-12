// よすぽさんの Library-Checker 
// Shortest Path (https://judge.yosupo.jp/problem/shortest_path)

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
using P = pair<long long, int>;
constexpr long long INF = 1LL << 60;

class Dijkstra {
    struct edge {
        int to;
        long long cost;
        edge(int to, long long cost) 
            : to(to), cost(cost) {}
    };
public:
    int V;                      // 頂点数
    vector<vector<edge>> edges; // 橋情報 from -> to のコスト
    vector<long long> dis;      // d[i]:=V[i] までの最短距離
    vector<int> prev;           // 経路復元

    Dijkstra(int size) 
        : V(size), edges(size), dis(size, INF), prev(size, -1) {}

    void add(int from, int to, long long cost) {
        edges[from].emplace_back(to, cost);
    }

    void dijkstra(int start) {
        // P -> first : 最短距離, second : 頂点の番号
        priority_queue<P, vector<P>, greater<P>> que;
        que.emplace(0, start);
        dis[start] = 0;

        while(!que.empty()) {
            P p = que.top();
            que.pop();
            int v = p.second;
            if(dis[v] < p.first){
                continue;
            }
            for(const edge e : edges[v]){
                if(dis[e.to] > dis[v] + e.cost) {
                    dis[e.to] = dis[v] + e.cost;
                    prev[e.to] = v;
                    que.emplace(dis[e.to], e.to);
                }
            }
        }
    }

    vector<int> get_path(int t) {
        vector<int> path;
        for( ; t != -1; t = prev[t]) {
            // t が start まで prev[t] をたどる
            path.push_back(t);
        }
        //このままだと t->start の順になっているので逆順にする
        reverse(path.begin(), path.end());
        return path;
    }

    // debug用
    void show(void) {
        for(const auto x : dis) {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main() {
    
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    
    Dijkstra dk(n);
    // 元々 0-index になっているので注意
    //     有向グラフになっているのも注意
    for(int i = 0; i < m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        dk.add(a, b, c);
    }

    dk.dijkstra(s);
    vector<int> path = dk.get_path(t);
    
    if(dk.dis[t] == INF){
        cout << -1 << endl;
        return 0;
    }

    int len = path.size();
    cout << dk.dis[t] << " " << len - 1 <<endl;
    for(int i = 0; i < len - 1; ++i){
        //      from                to
        cout << path[i] << " " << path[i+1] << endl;
    }
}