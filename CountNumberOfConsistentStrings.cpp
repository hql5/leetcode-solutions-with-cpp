/*
 * @Author: lhq
 * @Date: 2022-11-08 11:45:29
 * @LastEditTime: 2022-11-08 13:07:53
 * @LastEditors: lhq
 * @Description: words中的每个字符都在allowed中，就是一致字符串
 * @FilePath: \leetcode-solutions-with-cpp\CountNumberOfConsistentStrings.cpp
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool mask[26] = {false};
        for (char& c : allowed) {
            mask[c - 'a'] = true;    // 'a' - 'a' == 0 ==> mask[0]
        }

        int ret = 0;
        for (string& s : words) {
            bool exist = true;
            for (char& c : s) {
                if (!mask[c-'a']) {
                    //s中有字符不存在于allowed中
                    exist = false;
                    break;
                }
            }
            ret += exist;    //true == 1
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    cout << true;
    return 0;
}
