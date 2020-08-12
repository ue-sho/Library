// 最小全域木(minimum spaninng tree)
// プリム法
//
// AOJ GRL 2 A Minimum Spanning Tree
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A&lang=ja

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
using P = pair<int, int>;

struct edge {
    int to;   //到達点
    int cost; //移動コスト
    edge(int to, long long cost) 
        : to(to), cost(cost) {}
};

int prim(vector<vector<edge>>& edges, int V) {
    int res = 0;
    vector<bool> used(V, false);
    // P -> first : コスト, second : 行先
    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, 0);
    // コストが小さい順に出しいく
    while (!que.empty()) {
        P p = que.top();
        que.pop();
        if(used[p.second]){
            continue;
        }
        used[p.second] = true;
        res += p.first;
        for(const auto e : edges[p.second]){
            if(!used[e.to]){
                que.emplace(e.cost, e.to);
            }
        }
    }
    return res;
}

int main(){

	int v, e;
	cin >> v >> e;
    vector<vector<edge>> edges(v);
	for(int i = 0; i < e; ++i){
		int s, t, w;
		cin >> s >> t >> w;
		edges[s].emplace_back(t, w);
		edges[t].emplace_back(s, w);
	}

    cout << prim(edges, v) << endl;

    return 0;
}