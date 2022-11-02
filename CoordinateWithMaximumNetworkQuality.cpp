/*
 * @Author: lhq
 * @Date: 2022-11-02 10:33:45
 * @LastEditTime: 2022-11-02 13:02:53
 * @LastEditors: lhq
 * @Description: 网络信号最好的坐标
 * @FilePath: \leetcode-solutions-with-cpp\CoordinateWithMaximumNetworkQuality.cpp
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    float getDistance(vector<int>& t1, vector<int>& t2) {
        return sqrt((t2[1]-t1[1])*(t2[1]-t1[1]) + (t2[0]-t1[0])*(t2[0]-t1[0]));
    }

    bool isContainCoor(vector<int>& t1, vector<int>& t2, int radius) {
        float d = getDistance(t1, t2);
        return (d < radius) ? true:false;
    }

    int qualityBetween(vector<int>& t1, vector<int>& t2) {
        return ( floor(t2[2] / (1+getDistance(t1, t2))) );
    }
    
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        vector<int> qualitys;
        for (int i = 0; i < towers.size(); i++)
        {
            int tempQuality = towers[i][2];            
            for (int j = 0; j < towers.size(); j++)
            {
                if (i != j && isContainCoor(towers[i], towers[j], radius))
                {
                    tempQuality += qualityBetween(towers[i], towers[j]);
                }
            }
            qualitys.push_back(tempQuality);
        }
        
        int retIdx = max_element(qualitys.begin(), qualitys.end()) - qualitys.begin();
        vector<int> ret = { towers[retIdx][0], towers[retIdx][1]};
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution slu;
    vector<vector<int>> towers = {{2,1,9},{0,1,9}};
    int radius = 2;
    vector<int> dis = slu.bestCoordinate(towers, radius);
    std::cout << dis[0] << dis[1] << endl;
    return 0;
}
