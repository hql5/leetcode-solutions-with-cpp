/*
 * @Author: lhq
 * @Date: 2022-12-25 13:12:26
 * @LastEditTime: 2022-12-25 13:24:53
 * @LastEditors: lhq
 * @Description: 最长回文串（easy)
 * @FilePath: \leetcode-solutions-with-cpp\longest_palindrome.cpp
 */
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> cnt;
        int ret = 0;
        int flag = 0; // 有字符出现了1次

        for (auto &c : s)
        {
            cnt[c]++;
        }

        for (auto &elem : cnt)
        {
            if (elem.second > 1)
            {
                ret += elem.second;
            }
            else
            {
                flag = 1;
            }
        }
        if (flag)
            ret++;

        return ret;
    }
};

int main()
{
    Solution slu;
    string s = "abccccdd";
    cout << slu.longestPalindrome(s) << endl;

    return 0;
}