// ワーシャルフロイド(warshall_floyd)
// 計算量 O( N^3 )

#include <vector>

using namespace std;

const long long INF = 1LL << 60;

void WarshalFroyd(vector<vector<long long>> &d, int n)
{
    for (int k = 0; k < n; k++) {      // 経由する頂点
        for (int i = 0; i < n; i++) {  // 始点
            if (d[i][k] == INF) {
                continue;
            }
            for (int j = 0; j < n; j++) {  // 終点
                if (d[k][j] == INF) {
                    continue;
                }
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

/*
    for (int k = 0; k < n; k++) {          // 経由する頂点
        for (int i = 0; i < n; i++) {      // 始点
            for (int j = 0; j < n; j++) {  // 終点
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
*/
