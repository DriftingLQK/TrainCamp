#include "stdafx.h"

int Str_To_Int(string str, int *ResuleData,int *CheckData ,int numberbuffer)
{
	char *span;
	span = &str[0];
	int len = str.length();
	int sum[200], num = 0;   //�ַ����е����ִ洢�ͼ���	
	int numbercount = 0;           //�����ַ����е���������
	int repeat = 1;          //�ظ�����
	char cc = *span;
	while (cc != '\0')
	{
		if (*span >= '0'&& *span <= '9')   //�ж��ǲ��������ַ�
		{
			sum[num] = cc - '0';
			num++;
		}
		else
		{
			if (*span == ','&& num > 0)   // �����ָ����������������ִ�С
			{
				int kk;
				int temp = 0;
				for (int i = 0; i<num; i++)
				{
					kk = pow(10, num - i - 1);
					temp = kk * sum[i] + temp;
					sum[i] = 0;
				}
				num = 0;
				ResuleData[numbercount] = temp;
				numbercount++;
			}
			else if (*span == ','&& num == 0)
			{
				ResuleData[numbercount] = NULL;		
				CheckData[repeat] = numbercount;
				repeat++;
				numbercount++;
			}
		}
		span = span + 1;
		cc = *span;
		if (cc == '\0'&&num > 0)   //���һ���ַ�
		{
			int kk;
			int temp = 0;
			for (int i = 0; i<num; i++)
			{
				kk = pow(10, num - i - 1);
				temp = kk * sum[i] + temp;
				sum[i] = 0;
			}
			num = 0;
			ResuleData[numbercount] = temp;
			numbercount++;
		}
	}
	CheckData[0] = repeat - 1;
	return numbercount;
}

