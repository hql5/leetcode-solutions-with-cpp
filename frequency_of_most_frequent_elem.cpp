/*
 * @Author: lhq
 * @Date: 2022-12-13 23:51:08
 * @LastEditTime: 2022-12-14 01:08:31
 * @LastEditors: lhq
 * @Description: 最高频元素的频数
 * @FilePath: \leetcode-solutions-with-cpp\frequency_of_most_frequent_elem.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long total = 0;
        int l = 0, ret = 1;
        for (int r = 1; r < n; ++r) {
            total += (long long)(nums[r] - nums[r - 1]) * (r - l);
            while (total > k) {
                total -= nums[r] - nums[l]; //窗口缩小了最大值与最小值的差值
                ++l; //左边界右移
            }
            ret = max(ret, r - l + 1);
        }
        return ret;
    }
};

////超时
// class Solution {
// public:
//     int maxFrequency(vector<int>& nums, int k) {
//         int ret = 1, n = nums.size();
//         int tret = 1, gp = 0;
//         int tk = k;
//         sort(nums.begin(), nums.end(), less<int>());
//         for (int i = n-1; i > 0; i--) {
//             int j = i-1;
//             while (tk > 0 && j >= 0) {
//                 gp = nums[i] - nums[j];
//                 tk -= gp;
//                 if (tk >= 0)
//                     tret++;
//                 else
//                     break;
//                 j--;
//             }
//             ret = max(tret, ret);
//             tret = 1;
//             tk = k;
//         }
//         return ret;
//     }
// };

int main() {
    Solution slu;
    vector<int> v = {1,2,4};
    cout << slu.maxFrequency(v,5) << endl;
    // vector<int> v2(85,10000);
    // int ans = 0;
    // for (int i = 0; i < v.size(); i++) {
    //     ans += v2[i] - v[i];
    // }
    // cout << ans << endl;
    
    return 0;
}