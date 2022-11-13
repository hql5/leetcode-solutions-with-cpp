/*
 * @Author: lhq
 * @Date: 2022-11-13 16:04:14
 * @LastEditTime: 2022-11-13 16:14:24
 * @LastEditors: lhq
 * @Description: 自定义字符串排序，返回任意排列
 * @FilePath: \leetcode-solutions-with-cpp\custom_sort_string.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> val(26);
        for (int i = 0; i < order.size(); i++)
        {
            //order中的字符依次赋值1,2,...
            val[order[i] - 'a'] = i+1;
        }
        //对s进行排序，按照order字符出现的次序，val数组的值
        sort(s.begin(), s.end(), 
        [&] (char c1, char c2) {
            return val[c1-'a'] < val[c2-'a'];
        }
        );

        return s;
    }
};

int main(int argc, char const *argv[])
{
    Solution slu;
    cout << slu.customSortString("cba", "abcd") << endl;

    return 0;
}
