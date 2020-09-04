// ワーシャルフロイド(warshall_floyd) 計算量 O( N^3 )
//

#include <iostream>
#include <vector>
using namespace std;

void WarshalFroyd(vector<vector<long long>> &d, int n)
{
    for (int k = 0; k < n; k++) {          // 経由する頂点
        for (int i = 0; i < n; i++) {      // 始点
            for (int j = 0; j < n; j++) {  // 終点
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}
