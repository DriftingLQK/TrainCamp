#include "stdafx.h"


int StrToInt_New(char *InputData, int len, vector<int>&nums, vector<int>&flags)
{		
	nums.clear();//��������
	flags.clear();//��������
	
	int TransValue;
	char* p = NULL;
	p = InputData;
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		char cc = InputData[i];
		if (InputData[i] == ',')
		{
			TransValue = atoi(p);         //������ǰ��char��=��intת��
			
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
			p = InputData + i + 1;     //ָ�򶺺�֮��

		}
	}
	nums.push_back(atoi(p));            //�������������һλ
	return  nums.size();
}

