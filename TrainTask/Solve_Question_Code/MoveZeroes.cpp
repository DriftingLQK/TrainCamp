#include<iostream>
#include<vector>
using namespace std;

/*************************** 第二十题*************************************
[要求]
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
1. 必须在原数组上操作，不能拷贝额外的数组。
2. 尽量减少操作次数。
******************************************************************************/

void MoveZeroes(vector<int>& nums)
{
	
	unsigned int len = nums.size();
	if (len > 1)    //数组长度大于1
	{
		unsigned int span = 0;  //标定非零元素的位置
		int zero = 0;
		for (unsigned int i = 0; i < len ; i++)
		{			
			if (nums[i] != 0)   //遇到不为零的值，将指针所指位置的数值进行修改
			{
				if (span!=i)
				{
					nums[span] = nums[i];    // 数值修改
					nums[i] = zero;          //对应位置零
					//swap(nums[span], nums[i]);  //交换元素位置
				}
				span++;
			}
		}
	}
}