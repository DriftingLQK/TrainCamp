#include<iostream>
#include<vector>
using namespace std;

/*************************** �ڶ�ʮ��*************************************
[Ҫ��]
����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
1. ������ԭ�����ϲ��������ܿ�����������顣
2. �������ٲ���������
******************************************************************************/

void MoveZeroes(vector<int>& nums)
{
	
	unsigned int len = nums.size();
	if (len > 1)    //���鳤�ȴ���1
	{
		unsigned int span = 0;  //�궨����Ԫ�ص�λ��
		int zero = 0;
		for (unsigned int i = 0; i < len ; i++)
		{			
			if (nums[i] != 0)   //������Ϊ���ֵ����ָ����ָλ�õ���ֵ�����޸�
			{
				if (span!=i)
				{
					nums[span] = nums[i];    // ��ֵ�޸�
					nums[i] = zero;          //��Ӧλ����
					//swap(nums[span], nums[i]);  //����Ԫ��λ��
				}
				span++;
			}
		}
	}
}