/*
 * @Author: lhq
 * @Date: 2022-11-03 11:44:20
 * @LastEditTime: 2022-11-03 12:13:02
 * @LastEditors: lhq
 * @Description: 最大重复子字符串
 * @FilePath: \leetcode-solutions-with-cpp\MaximumRepeatingSubstring.cpp
 */
#include <iostream>
namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int ans = 0;
        string t = word;
        int x = sequence.size() / word.size();    //最大包含次数
        for (int k = 1; k <= x; ++k) {
            // 这里从小到大枚举重复值
            if (sequence.find(t) != string::npos) {
                ans = k;
            }
            t += word;
        }
        return ans;
    }
};
