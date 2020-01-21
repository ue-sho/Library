//dfs 一般的な形
const int MAX = 50;

int n;
bool graph[MAX][MAX];
bool visit[MAX];

void dfs(int x){

    if(visit[x]){ //訪問済み
        return;
    }

    visit[x] = true;
    rep(i, n){
        if(graph[x][i]){
            dfs(i);
        }
    }
}
/******************************************/
//color 初期値NIL Stackを使ったバージョン
const int MAX = 100000;
const int NIL = -1;

void dfs(int start_point, int id, vector<int> *graph, int *color, int n){
    
    stack<int> S;
    S.push(start_point);
    color[start_point] = id;

    while(!S.empty()){
        int node = S.top(); S.pop();
        rep(i, graph[node].size()){
            int v = graph[node][i];
            if(color[v] == NIL){
                color[v] = id;
                S.push(v);
            }
        }
    }
}

/****************************************************/
//bfs　スタート位置とゴール地点の最短経路の最大の長さを探す

const int INF = 1001001001;
//4近傍
const int di[] = {-1, 0, 1, 0};     //8近傍なら　{-1, -1, -1, 0, 0, 1, 1, 1}
const int dj[] = {0, -1, 0, 1};     //          {-1, 0, 1, -1, 1, -1, 0, 1}

void bfs(){
    
    int h, w;
    cin >> h >> w;

    vector<string> graph(h);
    rep(i, h){
        cin >> graph[i];
    }

    int ans = 0;
    rep(si, h){
        rep(sj, w){
            if(graph[si][sj] == '#'){
                continue;
            }
            vector<vector<int>> distance(h, vector<int>(w, INF));
            queue<pair<int, int>> que;
            auto update = [&](int i, int j, int x){
                if(distance[i][j] != INF){
                    return;
                }
                distance[i][j] = x;
                que.emplace(i, j);
            };
            update(si, sj, 0);

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

                    ans = max(ans, distance[ni][nj]);
                }
            }
        }
    }
    cout << ans << endl;
}


/***********************************/
//bfs　基本形

#define N 100
#define NIL -1
void bfs(const vector<vector<int> > &graph, int n, int starting_point){ 
    
    queue<int> q;
    vector<int> distance(n, NIL);

    q.push(starting_point);
    distance[starting_point] = 0;

    int node;
    while(!q.empty()){
        node = q.front(); q.pop();
        rep(i, graph[node].size()){
            if(distance[graph[node][i]] != NIL){
                continue; //もう探索済み
            }
            distance[graph[node][i]] = distance[node] + 1;
            q.push(graph[node][i]);
        }
    }


    rep(i, n){
        cout << i+1 << " " << distance[i] << endl;
    }
}