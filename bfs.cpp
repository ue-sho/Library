
/* 隣接リスト */
void bfs(){ 
    vector<vector<int>> graph
    
    queue<int> q;
    vector<int> distance(n, -1);

    q.push(0);
    distance[0] = 0;

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : graph[u]){
            if(distance[v] == -1){
                distance[v] = distance[u] + 1;
                q.push(v);
            }

        }
    }
}


/* 隣接行列 */

// 4近傍
const int di[] = {-1, 0, 1, 0};     //8近傍なら　{-1, -1, -1, 0, 0, 1, 1, 1}
const int dj[] = {0, -1, 0, 1};     //          {-1, 0, 1, -1, 1, -1, 0, 1}
// 8近傍
const int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};
// 6近傍
const int dy[6] =      {0, 1, 1, 0, -1, -1};
const int dx[2][6] = { {1, 1, 0, -1, 0, 1}, 
                        {1, 0, -1, -1, -1, 0} };

void bfs(){
    
    queue<P> q;
    vector<vector<int>> dis(h, vector<int>(w, -1));
    q.push({0, 0});
    dis[0][0] = 0;
    
    while(!q.empty()){
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();
        rep(i, 4){
            int y = ny + dy[i];
            int x = nx + dx[i];
            if(x < 0 || y < 0 || x >= w || y >= h){
                continue;
            }
            if(graph[y][x] == '#'){
                continue;
            }
            if(dis[y][x] == -1){
                dis[y][x] = dis[ny][nx] + 1;
                q.push({y, x});
            }
        }
    }
}