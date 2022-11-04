/*
 * @Author: lhq
 * @Date: 2022-11-04 09:31:09
 * @LastEditTime: 2022-11-04 10:04:43
 * @LastEditors: lhq
 * @Description: 到达某个数字
 * @FilePath: \leetcode-solutions-with-cpp\ReachANumber.cpp
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        int ret, num = 0;
        int t = abs(target);
        while (num < t || (num - t)%2 != 0) {
            num += ++ret;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution slu;
    // int a = 2;
    cout << slu.reachNumber(2);
    return 0;
}
