#include<iostream>
#include<vector>

using namespace  std;

/**************************�ڶ�ʮһ��**********************************
[Ҫ��]
����һ��32λ���з�������������Ҫ�����������ÿλ�ϵ����ֽ��з�ת��
�������ǵĻ���ֻ�ܴ洢���� 32 λ���з���������������ֵ��ΧΪ [-2^31,  2^31-1]��
�����������裬�����ת�����������ô�ͷ��� 0��
****************************************************************************/

int Reverse(int x)
{
	if (x > INT_MAX || x < INT_MIN || x == 0)  //�ж��������ݵ���ȷ��
	{
		return 0;
	}
	int  flag;//�ж����ݵ�����
	if (x < 0)
		flag = -1;
	else
		flag = 1;

	int saveinput;    //�洢�������
	if (x == INT_MIN)  //�������Сֵ-2147483648��	
	{
		saveinput = INT_MAX;  //ȡ����ֵ��������������ֵ�����β��7��8�Է�תӰ�첻��
	}
	else
	{
		saveinput = abs(x);			
	}

	int  result;               //   ��ֹ��ת��洢ֵ����int�����Χ
	int temp = saveinput, n = 0;
	while (temp)               //   ��ԭ�������ʾ
	{
		if (INT_MAX / 10 < n)      //  ���ֵ�����һλ�� 7 �����������������λ���ܴ���2
		{
			return 0;
		}
		else
		{
			n = n * 10 + temp % 10;
			temp = temp / 10;
		}

	}
	result = flag * n;

	if (result > INT_MAX || result < INT_MIN)
	{
		return 0;
	}
	return (int)result;
}


