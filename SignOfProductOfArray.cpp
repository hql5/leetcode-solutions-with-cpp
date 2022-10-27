/*
 * @Author: lhq
 * @Date: 2022-10-27 17:35:41
 * @LastEditTime: 2022-10-27 17:46:37
 * @LastEditors: lhq
 * @Description: 数组元素积的符号，正返回1，负返回-1，0返回0.
 * @FilePath: \leetcode-solutions-with-cpp\SignOfProductOfArray.cpp
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int posNum, negNum = 0;
        for (int i=0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                return 0;
            }
            else if (nums[i] < 0) {
                negNum++;
            }
            else {
                posNum++;
            }
        }
        if (negNum%2 == 1)
        {
            return -1;
        }
        else {
            return 1;
        }
        
    }
};

int main(int argc, char const *argv[])
{
    Solution slu;
    vector<int> nums;
    nums = {-1,1,-1,1,-1};
    cout << slu.arraySign(nums);
    return 0;
}
