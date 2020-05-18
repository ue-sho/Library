struct edge {
    int to;
    int cost;
};

void dijkstra(const vector<vector<edge>>& edges, vector<int>& distance, int start_point) {
    distance[start_point] = 0;

    // P -> first : 最短距離, second : 頂点の番号
    priority_queue<P, vector<P>, greater<P>> que;
    que.emplace(0, start_point);

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int next = p.second;
        if (distance[next] < p.first){
            continue;
        }
        for(const auto e : edges[p.second]){
            if(distance[e.to] > distance[next] + e.cost){
                distance[e.to] = distance[next] + e.cost;
                que.emplace(distance[e.to], e.to);
            }
        }
    }
}