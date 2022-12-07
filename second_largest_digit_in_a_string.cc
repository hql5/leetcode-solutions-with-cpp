/*
 * @Author: lhq
 * @Date: 2022-12-07 19:19:30
 * @LastEditTime: 2022-12-07 20:33:48
 * @LastEditors: lhq
 * @Description: 字符串中第二大的数字
 * @FilePath: \leetcode-solutions-with-cpp\second_largest_digit_in_a_string.cc
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int secondHighest(string s) {
        int n =  s.size();
        int max = -1, smax = -1;
        int i;
        for (i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                int num = s[i] - '0';
                if (max < num) {
                    smax = max;
                    max = num ;
                }
                else if (num < max && num  > smax ) { //重复数字只算一次
                    smax = num ;
                }
            }
        }
        return smax;
    }
};

int main() {
    Solution slu;
    cout << slu.secondHighest("ck077") << endl;
    return 0;
}