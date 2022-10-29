/*
 * @Author: lhq
 * @Date: 2022-10-28 13:54:22
 * @LastEditTime: 2022-10-28 15:33:29
 * @LastEditors: lhq
 * @Description: 子数组的最小值之和。（所有子数组）
 * @FilePath: \leetcode-solutions-with-cpp\SumOfSubarraysMinimums.cpp
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long ret = 0;
        stack<int> sta;
        int mod = int(1e9 + 7);
        for (int i=0; i <= arr.size(); i++) {
            while (!sta.empty() && arr[sta.top()] > arr[i]) {
                //栈不空，且栈顶元素大于入栈元素时，要出栈并计算arr[sta.top()]的辐射
                //范围和以该元素为中心的子数组和
                int cent = sta.top();    //出栈（下标），辐射范围中心点位置
                sta.pop();
                
                int left = !sta.empty() ? sta.top() : -1;   //辐射范围左区间是此时
                //栈顶元素（下标），最后一个元素没有左边范围
                int right = i;  //辐射范围右
                ret = (ret + long( (cent-left)*(right-cent)*arr[cent] )) % mod;
            }
            sta.push(i);    //栈顶元素小于入栈元素,入栈下标值
        }
        
        return int(ret);
    }
};

int main(int argc, char const *argv[])
{
    Solution slu;
    vector<int> arr = {11,81,94,43,3};
    cout << slu.sumSubarrayMins(arr) << endl;
    return 0;
}
