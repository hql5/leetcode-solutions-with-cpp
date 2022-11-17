/*
 * @Author: lhq
 * @Date: 2022-11-17 18:13:41
 * @LastEditTime: 2022-11-17 18:40:44
 * @LastEditors: lhq
 * @Description: 匹配子序列的单词数
 * @FilePath: \leetcode-solutions-with-cpp\number_of_matching_subsequences.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> pos(26);
        for (int i=0; i < s.size(); ++i) {
            pos[s[i] - 'a'].push_back(i);
        }
        int res = word.size();
        for (string &w : words) {
            //必不是子序列
            if (w.size() > s.size()) {
                --res;
                continue;
            }
            int p = -1; //当前指针
            for (char c : w) {
                auto &ps = pos[c - 'a'];
                auto it = upper_bound(ps.begin(), ps.end(), p);
                if (it == ps.end()) {   //在s中没有该字符
                    --res;
                    break;
                }
                p = *it;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution slu;
    cout << slu.numMatchingSubseq() << endl;

    return 0;
}
