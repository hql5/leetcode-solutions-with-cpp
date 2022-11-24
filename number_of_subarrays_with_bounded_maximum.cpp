/*
 * @Author: lhq
 * @Date: 2022-11-24 22:04:43
 * @LastEditTime: 2022-11-24 22:11:06
 * @LastEditors: lhq
 * @Description: 区间子数组的个数
 * @FilePath: \leetcode-solutions-with-cpp\number_of_subarrays_with_bounded_maximum.cpp
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int> &nums, int left, int right) {
        int n = nums.size(), ans = 0, i0 = -1, i1 = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > right) i0 = i;
            if (nums[i] >= left) i1 = i;
            ans += i1 - i0;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution slu;
    vector<int> v = {2,1,4,3};
    cout << slu.numSubarrayBoundedMax(v, 2, 3);

    return 0;
}
