/*
 * @Author: lhq
 * @Date: 2022-11-27 20:18:23
 * @LastEditTime: 2022-11-27 20:51:21
 * @LastEditors: lhq
 * @Description: #1752, 检查数组是否经排序和轮转得到
 * @FilePath: \leetcode-solutions-with-cpp\check_if_array_is_sorted_and_rotated.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size(), x = 0;
        // 判断是否非递减
        for (int i = 1; i < n; ++i)
        { 
            if (nums[i] < nums[i - 1])
            {
                x = i;
                break;
            }
        }
        // 非递减数组，不经过轮转即可得到
        if (x == 0)
        {
            return true;
        }
        // 剩下的数组中如果存在非递减，返回false
        for (int i = x + 1; i < n; ++i)
        {
            if (nums[i] < nums[i - 1])
            {
                return false;
            }
        }
        //两个数组都是非递减，判断最后一个元素是否小于第一个元素
        return nums[0] >= nums[n - 1];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {3, 4, 5, 1, 2};
    Solution slu;
    cout << slu.check(nums);

    return 0;
}
