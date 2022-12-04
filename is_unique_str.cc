/*
 * @Author: lhq
 * @Date: 2022-12-04 21:19:04
 * @LastEditTime: 2022-12-04 21:23:19
 * @LastEditors: lhq
 * @Description: 判断字符是否唯一
 * @FilePath: \leetcode-solutions-with-cpp\is_unique_str.cc
 */
#include <iostream>
using namespace std;

class Solution {
public:
    bool isUnique(string astr) {
        //位运算解决
        int mark = 0;
        for (char c : astr) {
            int f = c - 'a';
            if ((mark & (1 << f)) != 0) return false;
            else mark |= 1 << f;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    string s = "abc";
    Solution slu;
    cout << slu.isUnique(s) << endl;
    return 0;
}
