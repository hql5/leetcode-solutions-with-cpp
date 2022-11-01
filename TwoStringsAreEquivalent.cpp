/*
 * @Author: lhq
 * @Date: 2022-11-01 09:51:29
 * @LastEditTime: 2022-11-01 10:06:56
 * @LastEditors: lhq
 * @Description: 判断两个字符串是否相等
 * @FilePath: \leetcode-solutions-with-cpp\TwoStringsAreEquivalent.cpp
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        //p1指向word1的每个元素，i指向每个元素中的每个字符
        int p1=0, p2=0, i=0, j=0;
        while (p1 < word1.size() && p2 < word2.size()) {
            //第一个元素的第一个字符不相等
            if (word1[p1][i] != word2[p2][j]) { return false; }

            i++;
            if (i == word1[p1].size()) {
                p1++;
                i = 0;
            }
            j++;
            if (j == word2[p2].size()) {
                p2++;
                j = 0;
            }
        }
        //p1,p2都遍历到最后等于字符串长度
        return ( p1 == word1.size() && p2 == word2.size() );    
    }
};

int main(int argc, char const *argv[])
{
    Solution slu;
    vector<string> s1 = {"abc", "d", "defg"};
    vector<string> s2 = {"abcddefg"};
    cout << slu.arrayStringsAreEqual(s1,s2);

    return 0;
}
