/*
 * @Author: lhq
 * @Date: 2022-10-30 18:32:12
 * @LastEditTime: 2022-10-30 18:42:04
 * @LastEditors: lhq
 * @Description: 字母大小写转换全排列。回溯法解题。
 * @FilePath: \leetcode-solutions-with-cpp\LetterCasePermutation.cpp
 */
class Solution {
public:
    void dfs(string &s, int pos, vector<string> &res) {
        while (pos < s.size() && isdigit(s[pos])) {
            pos++;
        }
        if (pos == s.size()) {
            res.emplace_back(s);
            return;
        }
        s[pos] ^= 32;
        dfs(s, pos + 1, res);
        s[pos] ^= 32;
        dfs(s, pos + 1, res);
    }

    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        dfs(s, 0, ans);
        return ans;
    }
};