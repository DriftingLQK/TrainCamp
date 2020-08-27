
#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
using namespace std;

// bool ContainsNearbyDuplicate(vector<int>& nums, int k)
//bool ContainsNearbyDuplicate(vector<int>&nums, int k)
//{
//	int len = nums.size();  //计算数组大小
//	if (len<=0)
//	{
//		return false;
//	}
//	if (k<=0)
//	{
//		return false;
//	}
//	for (int i = 0; i<len - 1; i++)
//	{
//		for (int j = i + 1; j<len; j++)
//		{
//			if (nums[i] == nums[j])
//			{
//				int c = abs(i-j);
//				if (c <= k)
//				{
//					return true;
//				}
//				else
//				{
//					continue;
//				}
//		
//			}
//		}
//	}
//	return false;
//}
// unordered_map 方法
bool ContainsNearbyDuplicate(vector<int>& nums, int k)
{
	int len = nums.size();  //计算数组大小
	if (len <= 0)
	{
		return false;
	}
	if (k <= 0)
	{
		return false;
	}
	unordered_map<int, int> record;
	pair<int, int>Insert_Pair;

	for (unsigned int i = 0; i < nums.size(); ++i)
	{
		if (record.size()> (unsigned int)k)
		{
			record.erase(nums[i - k - 1]);
		}
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

