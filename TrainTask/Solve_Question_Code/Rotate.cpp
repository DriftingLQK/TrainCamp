#include<iostream>
#include<vector>

using namespace std;

/*********************�ڶ�ʮ����***************************************
[Ҫ��]
����һ�����飬�������е�Ԫ�������ƶ�k��λ�ã�����k�ǷǸ�����

[���]
�������������Ľ�����������������ֲ�ͬ�ķ������Խ��������⡣
Ҫ��ʹ�ÿռ临�Ӷ�Ϊ O(1) �� ԭ�� �㷨��
************************************************************************/

#pragma region    �����ⷨ ,����������и���
void Rotate(vector<int>& nums, int k)
{
	int len = nums.size();
	vector<int> backup(nums);  //����һ����ͬ�������������ݱ���
		if (len > 1)  //��len<=1,���ô���,���鱾��
		{
			unsigned int actual_k = k% nums.size();    //��ȥѭ����ʣ����λ����
			if (actual_k > 0)    //��Ҫ������λ
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

#pragma region  ��߷���һ��˫��forѭ��������λ
//void Rotate(vector<int>& nums, int k)
//{
//	int len = nums.size();
//	if (len > 1)  //��len<=1,���ô���,���鱾��
//	{
//		unsigned int actual_k = k% nums.size();    //��ȥѭ�����еģ�ʣ����λ����
//		if (actual_k > 0)    //��Ҫ������λ
//		{
//			int temp = 0;                  //�洢��ʱ�ƶ���ֵ
//			reverse(nums.begin(), nums.end());
//			for (unsigned int i = 0; i < actual_k; i++)
//			{
//				temp = nums[0];
//				for (unsigned int j = 0; j < nums.size() - 1; j++)
//				{
//					nums[j] = nums[j + 1];   //�������ǰ��λ
//				}
//				nums[nums.size() - 1] = temp;
//			}
//			reverse(nums.begin(), nums.end());
//		}
//
//	}
//}
#pragma endregion

#pragma region ��߷����������з�ת����
//void Rotate(vector<int>& nums, int k)
//{
//	int len = nums.size();
//	if (len > 1)  //��len<=1,���ô���,���鱾��
//	{
//		unsigned int actual_k = k% nums.size();    //��ȥѭ�����еģ�ʣ����λ����
//		if (actual_k > 0)    //��Ҫ������λ
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

#pragma region ��߷�������ѭ�����и�λ�ô�����δ���
//void Rotate(vector<int>& nums, int k)
//{
//	int len = nums.size();
//	if (len > 1)  //��len<=1,���ô���,���鱾��
//	{
//		unsigned int actual_k = k% nums.size();    //��ȥѭ�����еģ�ʣ����λ����
//		if (actual_k > 0)    //��Ҫ������λ
//		{
//
//		}
//
//	}
//}
#pragma endregion




