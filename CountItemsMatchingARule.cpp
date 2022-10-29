/*
 * @Author: lhq
 * @Date: 2022-10-29 18:32:56
 * @LastEditTime: 2022-10-29 18:33:27
 * @LastEditors: lhq
 * @Description: 统计满足规则的物品数量
 * @FilePath: \leetcode-solutions-with-cpp\CountItemsMatchingARule.cpp
 */
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        unordered_map<string, int> dictionary = {{"type", 0}, {"color", 1}, {"name", 2}};
        int res = 0, index = dictionary[ruleKey];
        for (auto &&item : items) {
            if (item[index] == ruleValue) {
                res++;
            }
        }
        return res;
    }
};