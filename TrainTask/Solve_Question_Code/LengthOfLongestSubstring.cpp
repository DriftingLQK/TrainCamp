#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;


/************************�ڶ�ʮ����***************************
[Ҫ��]
����һ���ַ����������ҳ����в������ظ��ַ�����Ӵ��ĳ��ȡ�
������ ASCII�ַ�һ��128��
**********************************************************/


int LengthOfLongestSubstring(char * s)
{
	int head = 0;
	int index = 0;
	string str = s;
	int maxLength = 0;
	int usedChar[128] = { 0 };
	char tempchar;
	int tempint;
	while (head < str.size())
	{

		tempchar = str[index];
		tempint = usedChar[str[index]];
		if (index < str.size() && tempint == 0)
		{
			tempchar = str[index];
			usedChar[tempchar]++;
			index++;
		}
		else
		{
			tempchar = str[head];
			usedChar[tempchar]--;
			head++;
		}
		maxLength = max(maxLength, index - head);
	}
	return maxLength;
}

//int LengthOfLongestSubstring(char * s)
//{
//	int maxlen =0,lentemp = 0;
//	char start;
//	string str = s;
//
//	int len_s = str.size();      //���ַ�����ĳ��ȣ�������\0
//	unordered_map<char,char>Letter;
//	int index = 0;
//	while (index<len_s)
//	{
//		for (unsigned int i = index; i < len_s; i++)
//		{
//			start = s[i];
//			if (Letter.find(start) != Letter.end())  //���и��ҵ�����ͬ��ĸ
//			{
//				maxlen = max(lentemp, maxlen);
//				Letter.clear();
//				index++;
//				lentemp = 0;
//				break;
//			}
//			else  //�����Ҳ���
//			{
//				Letter[s[i]] = s[i];     //����ĸ������ж�Ӧ�Ĺ�����           
//				lentemp++;          //���ȼ�һ
//			}
//		}
//	}
//	
//	return  maxlen = max(lentemp, maxlen);
//}
