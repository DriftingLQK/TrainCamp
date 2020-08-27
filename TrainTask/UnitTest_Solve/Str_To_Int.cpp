#include "stdafx.h"

int Str_To_Int(string str, int *ResuleData,int *CheckData ,int numberbuffer)
{
	char *span;
	span = &str[0];
	int len = str.length();
	int sum[200], num = 0;   //字符串中的数字存储和计数	
	int numbercount = 0;           //计算字符串中的整型数字
	int repeat = 1;          //重复个数
	char cc = *span;
	while (cc != '\0')
	{
		if (*span >= '0'&& *span <= '9')   //判断是不是数字字符
		{
			sum[num] = cc - '0';
			num++;
		}
		else
		{
			if (*span == ','&& num > 0)   // 遇到分隔符，计算整型数字大小
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
		if (cc == '\0'&&num > 0)   //最后一个字符
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

