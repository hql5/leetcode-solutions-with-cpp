/*
 * @Author: lhq
 * @Date: 2022-10-26 19:31:19
 * @LastEditTime: 2022-10-26 23:54:58
 * @LastEditors: lhq
 * @Description: 和至少为k的最短子数组。单调队列（元素单调递增的双端队列）
 * @FilePath: \leetcode-solutions-with-cpp\ShortestSubArrayWithSumAtLeastK.cpp
 */
class Solution {
public:
    int shortestSubarray(vector<int> &nums, int k) {
        int n = nums.size(), ans = n + 1;
        long s[n + 1];
        s[0] = 0L;
        for (int i = 0; i < n; ++i)
            s[i + 1] = s[i] + nums[i]; // 计算前缀和
        deque<int> q;
        for (int i = 0; i <= n; ++i) {
            long cur_s = s[i];
            while (!q.empty() && cur_s - s[q.front()] >= k) {
                ans = min(ans, i - q.front());
                q.pop_front(); // 优化一
            }
            while (!q.empty() && s[q.back()] >= cur_s)
                q.pop_back(); // 优化二
            q.push_back(i);
        }
        return ans > n ? -1 : ans;
    }
};