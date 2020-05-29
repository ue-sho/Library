#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> graph;

// 親だけ知っていれば良い
void dfs(int v, int pre = -1){
    for(auto u : graph[v]){
        if(u == pre){
            continue;
        }
        dfs(u, v);
    }
}

// 閉路がある
void dfs(int v, vector<bool>& visit){
    visit[v] = true;
    for(auto u : graph[v]){
        if(visit[u]){
            continue;
        }
        dfs(u, visit);
    }
}