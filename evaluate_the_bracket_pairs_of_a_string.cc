/*
 * @Author: lhq
 * @Date: 2022-12-06 21:11:18
 * @LastEditTime: 2022-12-06 22:14:02
 * @LastEditors: lhq
 * @Description: 替换字符串中的括号内容
 * @FilePath: \leetcode-solutions-with-cpp\evaluate_the_bracket_pairs_of_a_string.cc
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    string evaluate(string s, vector<vector<string>> &knowledge)
    {
        map<string, string> m;
        string ret = "", ck = "";
        int p1 = 0, p2 = 0, n = s.size();

        for (int i = 0; i < knowledge.size(); i++)
        {
            m.insert(make_pair(knowledge[i][0], knowledge[i][1]));
        }

        while (true)
        {
            while (p1 < n && s[p1] != 40) {
                ret += s[p1];
                p1++;
            }
            if (p1 == n)
                break;
            p2 = p1 + 1;
            while (p2 < n && s[p2] != 41)
            {
                ck += s[p2];
                p2++;
            }
            map<string, string>::iterator cr = m.find(ck);
            if (cr != m.end())
            {
                ret += (*cr).second;
            }
            else
            {
                ret += "?";
            }
            p1 = ++p2;
            ck = "";
        }
        return ret;
    }
};

int main()
{
    Solution slu;
    string s = "(name)is(age)yearsold";
    vector<vector<string>> d = {{"name", "bob"}, {"age", "two"}};
    cout << slu.evaluate(s, d);
    return 0;
}