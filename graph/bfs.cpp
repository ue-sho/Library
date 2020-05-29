#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/* 隣接リスト */
vector<int> bfs(vector<vector<int>>& graph){
    
    queue<int> q;
    vector<int> dis(n, -1);
    q.push(0);
    dis[0] = 0;

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : graph[u]){
            if(dis[v] == -1){
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return dis;
}


/* 隣接行列 */

// 4近傍
constexpr int di[] = {-1, 0, 1, 0};
constexpr int dj[] = {0, -1, 0, 1};
// 8近傍
constexpr int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
constexpr int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};
// 6近傍    
// 参考：JOI 2012 予選5 E イルミネーション(https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_e)
constexpr int dy[6]    = {0, 1, 1, 0, -1, -1};
constexpr int dx[2][6] = { {1, 1, 0, -1, 0, 1}, 
                           {1, 0, -1, -1, -1, 0} };

// 4近傍例
vector<vector<int>> bfs(vector<vector<int>>& graph){
    
    queue<pair<int, int>> q;
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
    return dis;
}