/*
 * @Author: lhq
 * @Date: 2022-11-15 10:51:04
 * @LastEditTime: 2022-11-15 12:41:50
 * @LastEditors: lhq
 * @Description: 卡车上的最大单元数
 * @FilePath: \leetcode-solutions-with-cpp\maximun_units_on_a_truck.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        //lambda表达式中，vector传递形参会占用较大的内存空间，使用引用！
        sort(boxTypes.begin(), boxTypes.end(),
            [&](vector<int> v1, vector<int> v2) {
                return v1[1] > v2[1];
            });
        int ret = 0;
        for (int i = 0; i < boxTypes.size(); i++)
        {
            if (truckSize > boxTypes[i][0]) {
                ret += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else
            {
                ret += truckSize * boxTypes[i][1];
                return ret;
            }
        }
        return ret; 
    }

    // int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    //     sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &a, const vector<int> &b) {
    //         return a[1] > b[1];
    //     });
    //     int res = 0;
    //     for (auto &boxType : boxTypes) {
    //         int numberOfBoxes = boxType[0];
    //         int numberOfUnitsPerBox = boxType[1];
    //         if (numberOfBoxes < truckSize) {
    //             res += numberOfBoxes * numberOfUnitsPerBox;
    //             truckSize -= numberOfBoxes;
    //         } else {
    //             res += truckSize * numberOfUnitsPerBox;
    //             break;
    //         }
    //     }
    //     return res;
    // }
};

int main(int argc, char const *argv[])
{
    Solution slu;
    vector<int> v1 = {1,3};
    vector<int> v2 = {2,2};
    vector<int> v3 = {3,1};
    vector<vector<int>> v= {v1, v2, v3};
    cout << slu.maximumUnits(v, 4);

    return 0;
}
