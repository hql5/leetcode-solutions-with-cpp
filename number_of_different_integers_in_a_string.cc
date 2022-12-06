/*
 * @Author: lhq
 * @Date: 2022-12-06 20:50:41
 * @LastEditTime: 2022-12-06 20:56:25
 * @LastEditors: lhq
 * @Description: 一个字符串中不同整数的数目
 * @FilePath: \leetcode-solutions-with-cpp\number_of_different_integers_in_a_string.cc
 */
#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    int numDifferentIntegers(string word) {
        int n = word.size();
        int p1=0, p2;
        set<int> m;
        while(true) {
            while (p1 < n && !isdigit(word[p1])) p1++;
            if (p1 == n) break;
            p2 = p1;
            while (p2 < n && isdigit(word[p2])) {
                p2++;
            }
            p1 = p2;
            while (p2 - p1 > 1 && word[p1] == '0') { // 去除前导 0
                p1++;
            }
            m.insert(word.substr(p1, p2 - p1));
        }
        return m.size();
    }
};

int main() {
    Solution slu;
    string s = "a123bc34d8ef34";
    cout << slu.numDifferentIntegers(s) << endl;
}