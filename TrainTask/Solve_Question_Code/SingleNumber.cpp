#include<iostream>
#include<vector>

using namespace std;

/****************************��ʮ����***********************************
[Ҫ��]
����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�

[���]
����㷨Ӧ�þ�������ʱ�临�Ӷȡ� ����Բ�ʹ�ö���ռ���ʵ����
*************************************************************************/


int SingleNumber(vector<int>& nums) 
{
	if (nums.size()%2==0)   //�����ڵ�����ͬ����  ����ڶ����ͬ����
	{
		return NULL;
	}
	int result = NULL;
	int value = NULL;
	for (unsigned int i = 0; i<nums.size(); i++)
	{
		value = nums[i];
		result = result ^ value;    //��λ���
	}
	return result;
}
