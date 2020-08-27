#include<iostream>
#include<vector>

using namespace std;

/****************************第十四题***********************************
[要求]
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

[提高]
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
*************************************************************************/


int SingleNumber(vector<int>& nums) 
{
	if (nums.size()%2==0)   //不存在单个不同的数  或存在多个不同的数
	{
		return NULL;
	}
	int result = NULL;
	int value = NULL;
	for (unsigned int i = 0; i<nums.size(); i++)
	{
		value = nums[i];
		result = result ^ value;    //按位异或
	}
	return result;
}
