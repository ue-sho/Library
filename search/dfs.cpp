vector<vector<int>> graph;

void dfs(int v, int pre = -1){
    for(auto u : graph[v]){
        if(u == pre){
            continue;
        }
        dfs(u, v);
    }
}
