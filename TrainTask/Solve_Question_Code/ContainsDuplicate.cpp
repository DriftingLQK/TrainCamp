#include <iostream>
#include <vector>
#include <algorithm>    ///����ؼ�ͷ�ļ� 
#include <unordered_map>
using namespace std;

/****************************�����⣺*****************************
[Ҫ��]
����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء��������һֵ�������г����������Σ���������true �����������ÿ��Ԫ�ض�����ͬ���򷵻�false ��
******************************************************************/
//
//bool ContainsDuplicate(vector<int>& nums)
//{
//	if (nums.size()<=1)
//	{
//		return false;
//	}
//	sort(nums.begin(), nums.end());       ///������������ 
//	for (int i = 0; i<nums.size()-1; i++)
//	{
//		if (nums[i] == nums[i + 1])
//		{
//			return true;
//		}
//	}
//	return false;
//}

// unordered_map ����
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

