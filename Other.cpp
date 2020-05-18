// 最小全域木(minimum spaninng tree)　// コストが最小になるような木を作る
struct edge {
    int from, to;
    int cost;
};

int prim(vector<vector<edge>>& edges, int V) {
    int res = 0;
    vector<bool> used(V, false);
    // P -> first : コスト, second : 行先  // コストが小さい順に出しいく
    priority_queue<P, vector<P>, greater<>> priorityQueue;
    priorityQueue.emplace(0, 0);
    while (!priorityQueue.empty()) {
        P p = priorityQueue.top();
        priorityQueue.pop();
        if(used[p.second]){
            continue;
        }
        used[p.second] = true;
        res += p.first;
        for(edge<T> &e : edges[p.second]){
            if(!used[e.to]){
                priorityQueue.push({e.cost, e.to});
            }
        }
    }
    return res;
}


// 逆元
int mod_inv(int a){
    ll b = mod, u = 1, v = 0;
    while(b){
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= mod;
    if (u < 0){
        u += mod;
    }
    return u;
}

// ワーシャルフロイド
void warshall_floyd(int n) {
  for (int k = 0; k < n; k++){
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

//最大公約数
template <class T>
T gcd(T a, T b) {

    if(b == 0){
        return a;
    }
    else{
        gcd(b, a%b);
    }
}

//最小公倍数
template <class T>
T lcm(T a, T b){

    T g = gcd(a, b);

    return a / g * b;
}

//約数列挙
vector<int> divisor(int n){

    vector<int> ret;
    for(int i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n){
                ret.push_back(n / i);
            } 
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

// 素因数分解
// pairのfirstに素因数　secondに素因数の数
template <class T>
vector<pair<T, int>> factorize(T num){

    vector<pair<T, int>> res;
    for(T i = 2; i * i <= num; ++i){
        if(num % i){  //割り切れないなら素因数ではない
            continue;
        }
        res.emplace_back(i, 0);
        while(num % i == 0){
            res.back().second++;
            num /= i;
        }
    }
    if(num != 1){
        res.emplace_back(num, 1);
    }
    return res;
}