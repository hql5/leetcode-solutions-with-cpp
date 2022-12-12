/*
 * @Author: lhq
 * @Date: 2022-12-12 14:47:56
 * @LastEditTime: 2022-12-12 15:03:59
 * @LastEditors: lhq
 * @Description: 
 * @FilePath: \leetcode-solutions-with-cpp\min_operations_move_balls_to_boxes.cpp
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int left = boxes[0] - '0', c = 0, right = 0;
        for (int i = 1; i < n; i++ ) {
            if (boxes[i] == '1') {
                c += i; // boxes[0]的操作数
                right++;
            }
        }
        vector<int> ret(n,0);
        ret[0] = c;
        for (int j = 1; j < n; j++) {
            c += left - right;
            if (boxes[j] == '1') {
                left++;
                right--; 
            }
            ret[j] = c;
        }
        return ret;
    }
};

int main() {
    Solution slu;
    string s = "110";
    slu.minOperations(s);
    
    return 0;
}