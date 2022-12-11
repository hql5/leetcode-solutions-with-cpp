/*
 * @Author: lhq
 * @Date: 2022-12-11 22:59:07
 * @LastEditTime: 2022-12-11 23:36:31
 * @LastEditors: lhq
 * @Description: 最少操作使数组递增
 * @FilePath: \leetcode-solutions-with-cpp\minimum_operations_to_make_array_increasing.cpp
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ret = 0, c = 0;
        for (int i=0; i < n-1; i++ ) {
            if (nums[i] < nums[i+1]) {cout << "yes" << endl;}
            else {
                c = nums[i] - nums[i+1] + 1;
                nums[i+1] += c;
                ret += c;
            }
        }
        return ret;
        
    }
};

int main() {
    Solution slu;
    vector<int> n = {1,1,1};
    cout << slu.minOperations(n) << endl;
    
    return 0;
}