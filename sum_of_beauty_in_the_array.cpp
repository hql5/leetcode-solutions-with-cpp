/*
 * @Author: lhq
 * @Date: 2022-12-24 11:45:51
 * @LastEditTime: 2022-12-24 13:19:17
 * @LastEditors: lhq
 * @Description: 一个数组的美丽值之和
 * @FilePath: \leetcode-solutions-with-cpp\sum_of_beauty_in_the_array.cpp
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int sumOfBeauties(vector<int> &nums)
	{
		int n = nums.size();
		vector<int> lmx(n, INT_MIN);
		lmx[0] = nums[0];
		vector<int> rmi(n, INT_MAX);
		rmi[n - 2] = nums[n - 2];

		for (int i = 1; i < n; i++)
		{
			lmx[i] = max(nums[i - 1], lmx[i - 1]);
		}
		for (int i = n - 2; i > 0; i--)
		{
			rmi[i] = min(nums[i + 1], rmi[i + 1]);
		}

		int ret = 0;
		for (int i = 1; i < n - 1; i++)
		{
			if (nums[i] > lmx[i] && nums[i] < rmi[i])
			{
				ret += 2;
			}
			else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1])
			{
				ret++;
			}
			else
			{
				;
			}
		}

		return ret;
	}
};

int main()
{
	Solution slu;
	vector<int> v = {1, 2, 3};

	cout << slu.sumOfBeauties(v) << endl;

	return 0;
}