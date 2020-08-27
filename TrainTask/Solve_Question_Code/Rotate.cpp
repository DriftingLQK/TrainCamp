#include<iostream>
#include<vector>

using namespace std;

/*********************第二十二题***************************************
[要求]
给定一个数组，将数组中的元素向右移动k个位置，其中k是非负数。

[提高]
尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
要求使用空间复杂度为 O(1) 的 原地 算法。
************************************************************************/

#pragma region    基本解法 ,开辟数组进行覆盖
void Rotate(vector<int>& nums, int k)
{
	int len = nums.size();
	vector<int> backup(nums);  //定义一个相同的容器进行数据备份
		if (len > 1)  //当len<=1,不用处理,数组本身
		{
			unsigned int actual_k = k% nums.size();    //除去循环，剩余移位次数
			if (actual_k > 0)    //需要进行移位
			{
				for (unsigned int i = 0; i < len - actual_k; i++)
				{
					nums[i+ actual_k] = backup[i];
				}
				for (unsigned int i = len-actual_k; i < len; i++)
				{
					nums[i - len + actual_k ] = backup[i];
				}
			}
	
		}
}
#pragma endregion

#pragma region  提高方法一，双重for循环进行移位
//void Rotate(vector<int>& nums, int k)
//{
//	int len = nums.size();
//	if (len > 1)  //当len<=1,不用处理,数组本身
//	{
//		unsigned int actual_k = k% nums.size();    //出去循环进行的，剩余移位次数
//		if (actual_k > 0)    //需要进行移位
//		{
//			int temp = 0;                  //存储临时移动的值
//			reverse(nums.begin(), nums.end());
//			for (unsigned int i = 0; i < actual_k; i++)
//			{
//				temp = nums[0];
//				for (unsigned int j = 0; j < nums.size() - 1; j++)
//				{
//					nums[j] = nums[j + 1];   //后面的向前移位
//				}
//				nums[nums.size() - 1] = temp;
//			}
//			reverse(nums.begin(), nums.end());
//		}
//
//	}
//}
#pragma endregion

#pragma region 提高方法二，进行翻转处理
//void Rotate(vector<int>& nums, int k)
//{
//	int len = nums.size();
//	if (len > 1)  //当len<=1,不用处理,数组本身
//	{
//		unsigned int actual_k = k% nums.size();    //出去循环进行的，剩余移位次数
//		if (actual_k > 0)    //需要进行移位
//		{	
//			reverse(nums.begin(), nums.end());
//			reverse(nums.begin(), nums.begin() + actual_k);
//			reverse(nums.begin() + actual_k, nums.end());
//			
//		}
//
//	}
//}
#pragma endregion

#pragma region 提高方法三，循环进行各位置处理，暂未完成
//void Rotate(vector<int>& nums, int k)
//{
//	int len = nums.size();
//	if (len > 1)  //当len<=1,不用处理,数组本身
//	{
//		unsigned int actual_k = k% nums.size();    //出去循环进行的，剩余移位次数
//		if (actual_k > 0)    //需要进行移位
//		{
//
//		}
//
//	}
//}
#pragma endregion




