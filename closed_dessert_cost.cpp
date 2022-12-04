/*
 * @Author: lhq
 * @Date: 2022-12-04 19:59:46
 * @LastEditTime: 2022-12-04 20:50:16
 * @LastEditors: lhq
 * @Description: 最接近目标价格的甜点成本
 * @FilePath: \leetcode-solutions-with-cpp\closed_dessert_cost.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int ret = 0x3f3f3f;

    void dfs(int x, int sum, int t, vector<int>& tc)
    {
        int a = abs(t - sum);
        int b = abs(t - ret);
        if (a < b) ret = sum;
        if (a == b && sum < ret) ret = sum;
        if (sum > t) return;
        for (int i = x; i < tc.size(); i++) {
            dfs(i+1, sum+tc[i], t, tc);
            dfs(i+1, sum+2*tc[i], t, tc);
        }
    }

    int closestCost(vector<int> &bc, vector<int> &tc, int t)
    {
        int mbc = *min(bc.begin(), bc.end());
        for (int tbc : bc)
        {
            dfs(0, tbc, t, tc);
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution slu;
    vector<int> c1 = {1, 7};
    vector<int> c2 = {3, 4};
    int t = 10;
    cout << slu.closestCost(c1, c2, t);

    return 0;
}
