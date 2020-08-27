#include <iostream>
#include <vector>
#include <algorithm>    ///排序关键头文件 
#include <unordered_map>
using namespace std;

/****************************第六题：*****************************
[要求]
给定一个整数数组，判断是否存在重复元素。如果任意一值在数组中出现至少两次，函数返回true 。如果数组中每个元素都不相同，则返回false 。
******************************************************************/
//
//bool ContainsDuplicate(vector<int>& nums)
//{
//	if (nums.size()<=1)
//	{
//		return false;
//	}
//	sort(nums.begin(), nums.end());       ///容器数组排序 
//	for (int i = 0; i<nums.size()-1; i++)
//	{
//		if (nums[i] == nums[i + 1])
//		{
//			return true;
//		}
//	}
//	return false;
//}

// unordered_map 方法
bool ContainsDuplicate(vector<int>& nums)
{
	if (nums.size() <= 1)
	{
		return false;
	}
	unordered_map<int, int> record;
	pair<int, int>Insert_Pair;

	for (unsigned int i = 0; i < nums.size(); ++i)
	{
		if (record.find(nums[i]) == record.end())
		{
			Insert_Pair = { nums[i], nums[i] };
			record.insert(Insert_Pair);
		}
		else
		{
			return true;
		}

	}
	return false;
}

