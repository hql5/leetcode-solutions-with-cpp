/*
 * @Author: lhq
 * @Date: 2022-10-24 19:32:44
 * @LastEditTime: 2022-10-24 20:08:21
 * @LastEditors: lhq
 * @Description: 将一个数组划分为两个连续数组
 * @FilePath: \leetcode-solutions-with-cpp\PatritionArrayIntoDisjointIntervals.cpp
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& num) {
        int len = num.size();
        int idx = 0;    //标记返回位置
        int max = num[0];   //记录当前循环最大值
        int left_max = max; //记录左边数组的最大值
        for (int i=0; i < len; i++) {
            if (left_max > num[i]) {
                idx = i;
                left_max = max;     //idx位置右边有值更小，更新idx到该值
            }
            else {
                max = std::max(max, num[i]);     //右数组值更大，更新最大值（截止到当前位置i，包括左右数组）
            }
        }
        //循环结束后，max值是整个数组最大值，idx所在位置右边值都比num[idx]大

        return idx+1;
    }
};

int main() {
    int tnum;
    vector<int> num;

    Solution slu;
    slu.partitionDisjoint(num);

    return 0;
}