/*
 * @Author: lhq
 * @Date: 2022-11-06 20:33:28
 * @LastEditTime: 2022-11-06 20:33:31
 * @LastEditors: lhq
 * @Description: 设计GOAL解析器（字符串）
 * @FilePath: \leetcode-solutions-with-cpp\GOAL.cpp
 */
class Solution {
public:
    string interpret(string command) {
        string res;
        for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'G') {
                res += "G";
            } else if (command[i] == '(') {
                if (command[i + 1] == ')') {
                    res += "o";
                } else {
                    res += "al";
                }
            }
        }
        return res;
    }
};