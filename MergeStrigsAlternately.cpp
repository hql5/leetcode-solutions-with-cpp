/*
 * @Author: lhq
 * @Date: 2022-10-23 19:47:24
 * @LastEditTime: 2022-10-23 20:13:45
 * @LastEditors: lhq
 * @Description: 交替合并字符串
 * @FilePath: \leetcode-solutions-with-cpp\n1768.cpp
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // cout << word1.size() << endl;  
        int len1 = word1.size();
        int len2 = word2.size();
        int i = 0, j = 0;

        string res;
        res.reserve(len1 + len2);

        while (i < len1 || j < len2) {
            if (i < len1) {
                res.push_back(word1[i]);
                ++i;
            }
            if (j < len2) {
                res.push_back(word2[j]);
                ++j;
            }
        }
        return res;
    }
};

int main() {
    string s1, s2;
    cin >> s1;
    cin >> s2;

    Solution slu;
    cout << slu.mergeAlternately(s1, s2);

    return 0;
}