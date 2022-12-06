/*
 * @Author: lhq
 * @Date: 2022-12-05 21:58:24
 * @LastEditTime: 2022-12-06 16:51:29
 * @LastEditors: lhq
 * @Description: 01背包问题。动态规划求解
 * @FilePath: \leetcode-solutions-with-cpp\01_bag.cc
 */
#include <iostream>
#include <vector>
using namespace std;

#define max(a,b) a>b?a:b

int main(int argc, char const *argv[])
{
    vector<int> w, v;
    // vector<vector<int>> dp;
    vector<int> dp;
    int V, n;

    while (cin >> V >> n)
    {
        w.clear();
        v.clear();
        dp.clear();
        w.push_back(0);
        v.push_back(0);

        //输入每个物体体积，价值
        for (int i=1; i <= n; i++) {
            int cW, cV;
            cin >> cW >> cV;
            w.push_back(cW);
            v.push_back(cV);
        }

        //初始化dp矩阵,n*V
        // for (int i=0; i <=n; i++) {
        //     vector<int> buff(V+1, 0);
        //     dp.push_back(buff);
        // }
        //i-1之前的数据不需要保存，所以dp矩阵只需要两行V+1大小即可；又因为j是从背
        // 包容量V开始遍历，即从大到小遍历，保证了dp[j]和dp[j-w[i]]里面存的是i-1次遍
        // 历的结果，因此dp矩阵只需要一行V+1大小即可。
        dp = vector<int>(V+1, 0);

        //动态规划过程
        // for (int i=1; i <= n; i++) {
        //     for (int j=V; j >= 0; j--) {
        //         if (j >= w[i]) {
        //             dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
        //         }
        //         else {
        //             dp[i][j] = dp[i-1][j];
        //         }
        //     }
        // }

        //优化：求dp矩阵第i行只需要第i-1行的数据，那么第i-2行及之前的数据可以清除；同时遍历每一行的时候只用到了当前背包容量j和j-w[i]的数据，也就是求第i行时只需要第i-1行中小于等于j的数据。
        for (int i=1; i <= n; i++) {
            for (int j=V; j >= w[i]; j--) {
                if (j >= w[i]) {
                    dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
                }
                // else {
                //     dp[j] = dp[j];
                // }
            }
        }

        int ret = dp[V];
        cout << ret << endl;
    }
    
    return 0;
}
