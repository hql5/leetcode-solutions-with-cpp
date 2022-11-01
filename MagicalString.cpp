/*
 * @Author: lhq
 * @Date: 2022-10-31 21:04:18
 * @LastEditTime: 2022-11-01 09:49:51
 * @LastEditors: lhq
 * @Description: 神奇字符串（Magical String），连续出现次数组成字符串本身。
 * @FilePath: \leetcode-solutions-with-cpp\MagicalString.cpp
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        string s = "\1\2\2"; // 值就是 1,2,2，这样就可以直接用 s[i] 当作个数
        for (int i = 2; s.length() < n; ++i)
            s += string(s[i], s.back() ^ 3); // 1^3=2, 2^3=1，这样就能在 1 和 2 之间转换
        return count(s.begin(), s.begin() + n, 1);
    }
};


int main(int argc, char const *argv[])
{
    Solution slu;
    cout << slu.magicalString(6);

    return 0;
}
