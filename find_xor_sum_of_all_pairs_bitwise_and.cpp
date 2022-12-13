/*
 * @Author: lhq
 * @Date: 2022-12-13 16:50:52
 * @LastEditTime: 2022-12-13 17:05:14
 * @LastEditors: lhq
 * @Description: 所有数对按位与结果的异或和
 * @FilePath: \leetcode-solutions-with-cpp\find_xor_sum_of_all_pairs_bitwise_and.cpp
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size(), n2 = arr2.size();
        if (n1 == 1 && n2 == 1) {
            return (arr1[0] & arr2[0]);
        }
        vector<int> tmp;
        int ret = 0;
        for (int i = 0; i < n1; i++) {
            int t1 = arr1[i];
            for (int j = 0; j < n2; j++) {
                int t2 = arr2[j];
                // tmp[n3] = arr1[i] & arr2[j];
                auto&& t3 = t1 & t2;
                tmp.push_back(t3);
            }
        }
        for (int i = 0; i < tmp.size(); i++) {
            ret ^= tmp[i];
        }
        return ret;
    }
};

int main() {
    Solution slu;
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {6,5};
    cout << slu.getXORSum(v1, v2) << endl;
    
    return 0;
}