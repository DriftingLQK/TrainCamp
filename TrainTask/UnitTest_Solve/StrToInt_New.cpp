#include "stdafx.h"


int StrToInt_New(char *InputData, int len, vector<int>&nums, vector<int>&flags)
{		
	nums.clear();//清理数据
	flags.clear();//清理数据
	
	int TransValue;
	char* p = NULL;
	p = InputData;
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		char cc = InputData[i];
		if (InputData[i] == ',')
		{
			TransValue = atoi(p);         //逗号以前的char《=》int转换
			
			if (TransValue == 0)
			{
				char dd = InputData[i - 1];
				if (dd!='0')
				{
					flags.push_back(count);
					cout << flags.back()<<endl;
				}
			}
			nums.push_back(TransValue);
			count++;
			p = InputData + i + 1;     //指向逗号之后

		}
	}
	nums.push_back(atoi(p));            //补上数组中最后一位
	return  nums.size();
}

