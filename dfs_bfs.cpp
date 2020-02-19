//dfs 一般的な形
vector<vector<int>> graph;

void dfs(int node, int pre = -1){
    for(auto u : graph[node]){
        if(u == pre){
            continue;
        }
        dfs(u, node);
    }
}

/*bfs***************************************************/

const int INF = 1001001001;
//4近傍
const int di[] = {-1, 0, 1, 0};     //8近傍なら　{-1, -1, -1, 0, 0, 1, 1, 1}
const int dj[] = {0, -1, 0, 1};     //          {-1, 0, 1, -1, 1, -1, 0, 1}

void bfs(){

    vector<vector<int>> distance(h, vector<int>(w, INF));
    queue<P> que;
    auto update = [&](int i, int j, int x){
        if(distance[i][j] != INF){
            return;
        }
        distance[i][j] = x;
        que.emplace(i, j);
    };
    update(0, 0, 0);

    while(!que.empty()){
        int i = que.front().first;
        int j = que.front().second;
        que.pop();
        rep(direction, 4){
            int ni = i + di[direction];
            int nj = j + dj[direction];
            if(ni < 0 || ni >= h || nj < 0 || nj >= w){
                continue;
            }
            if(graph[ni][nj] == '#'){
                continue;
            }
            update(ni, nj, distance[i][j]+1);
        }
    }
}


/*bfs***************************************************/
vector<vector<int>> graph
void bfs(){ 
    
    queue<int> q;
    vector<int> distance(n, INF);

    q.push(0);
    distance[0] = 0;

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : graph[u]){
            if(distance[graph[u][v]] != INF){
                continue; //もう探索済み
            }
            distance[graph[u][v]] = distance[u] + 1;
            q.push(graph[u][v]);
        }
    }
}