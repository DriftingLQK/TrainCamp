#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;


/************************第二十四题***************************
[要求]
给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。
分析： ASCII字符一共128个
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
//	int len_s = str.size();      //求字符数组的长度，不包括\0
//	unordered_map<char,char>Letter;
//	int index = 0;
//	while (index<len_s)
//	{
//		for (unsigned int i = index; i < len_s; i++)
//		{
//			start = s[i];
//			if (Letter.find(start) != Letter.end())  //表中刚找到了相同字母
//			{
//				maxlen = max(lentemp, maxlen);
//				Letter.clear();
//				index++;
//				lentemp = 0;
//				break;
//			}
//			else  //表中找不到
//			{
//				Letter[s[i]] = s[i];     //将字母存入表中对应的规则下           
//				lentemp++;          //长度加一
//			}
//		}
//	}
//	
//	return  maxlen = max(lentemp, maxlen);
//}
