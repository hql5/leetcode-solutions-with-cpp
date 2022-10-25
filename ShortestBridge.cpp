/*
 * @Author: lhq
 * @Date: 2022-10-25 19:45:50
 * @LastEditTime: 2022-10-25 20:38:20
 * @LastEditors: lhq
 * @Description: 最短的桥
 * @FilePath: \leetcode-solutions-with-cpp\ShortestBridge.cpp
 */
#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    void findIsland1(vector<vector<int>>& grid, queue<pair<int, int>>& edge)
    {
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == 1)
                {
                    dfs(grid, i, j, edge);
                    return;
                }   
            }
        }
    }

    void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& edge)
    {
        //超出范围
        if(!(i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size()))
            return;
        //边缘海域，插入队列并置为2，防止重复访问
        if(grid[i][j] == 0)
        {
            edge.push(make_pair(i, j));
            grid[i][j] = 2;
            return;
        }
        else if(grid[i][j] == 2)
            return;
        //岛屿
        grid[i][j] = 2;
        dfs(grid, i+1, j, edge);
        dfs(grid, i-1, j, edge);
        dfs(grid, i, j+1, edge);
        dfs(grid, i, j-1, edge);
    }

public:
    int shortestBridge(vector<vector<int>>& grid) 
    {
        int ret = 0;
        vector<vector<int>> direction = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        //先找到岛屿1的所有边缘海域的位置
        queue<pair<int, int>> edge;
        findIsland1(grid, edge);
        
        //逐层扩张边缘海域，直到遇到另一座岛屿
        while(!edge.empty())
        {
            ++ret;
            int n = edge.size();
            while(n--)
            {
                pair<int, int> coor = edge.front();
                edge.pop();
                int i, j;
                //向四个方向扩张
                for(int k = 0; k < 4; ++k)
                {
                    i = coor.first + direction[k][0];
                    j =  coor.second + direction[k][1];
                    //如果超出范围
                    if(!(i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size()))
                        continue;
                    //岛内元素
                    else if(grid[i][j] == 2)
                        continue;
                    //边缘海域，插入队列并置为2
                    else if(grid[i][j] == 0)
                    {
                        edge.push(make_pair(i, j));
                        grid[i][j] = 2;
                    }
                    //遇到另一个岛屿
                    else if(grid[i][j] == 1)
                        return ret;
                }
            }
        }
        return 0;
    }
};