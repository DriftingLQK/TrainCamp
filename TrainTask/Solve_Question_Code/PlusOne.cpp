#include<iostream>
#include<vector>

using namespace std;
/****************************��ʮ����**************************
[Ҫ��]
����һ����������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�
����Լ���������� 0 ֮�⣬��������������㿪ͷ��
**********************************************************/


vector<int> PlusOne(vector<int>& digits)
{
	reverse(digits.begin(), digits.end());//��ת����������
	vector<int>Result(digits);

	if (digits[0] < 9)        //������һλС�ھ� �������ֱ�Ӽ�
	{
		Result[0]++;
	}
	else                     //������һλ���ڵ��ھ� ������Ҫ���н�λ����
	{
		int oneplus = 0;         //����һ����Ӻ�ı���
		int index = 0;
		unsigned int flag = 1;
		while (index < digits.size())
		{
			oneplus = digits[index] + flag; //�����������е������λ��־���
			if (oneplus > 9)                //�������9 ���н�λ
			{
				Result[index] = 0;          //����е���������
				flag = 1;                   //��λ�����һ
			}
			else                            //���û�н�λ              
			{
				Result[index] = oneplus;    //ֱ�ӽ���ӵĽ������
				flag = 0;
			}
			index++;
		}
		if (flag != 0)
		{
			Result.push_back(flag);
		}
	}
	reverse(Result.begin(), Result.end());//��ת����õ�������
	return Result;
}
