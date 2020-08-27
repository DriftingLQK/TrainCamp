#include<iostream>
#include <unordered_map>
#include <vector>
using namespace std;
/*******************************第十五题********************
[要求]
给定一种规律pattern和一个字符串str，判断str是否遵循相同的规律。
这里的遵循指完全匹配。
例如：pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
****************************************************************/
bool WordPattern(string Pattern, string str)
{

	if (Pattern.empty() || str.empty())   //如果规则或者字符串为空，则输出false
		return false;

	unordered_map <char, string> PtoW_map;   // 规则与单词匹配表
	unordered_map <string, char> WtoP_map;   // 单词表（查验）

	vector<string>StrWord;  //存储各单词
#pragma region     先将字符串以空格隔开，存储到向量中
	int pos = 0;
	int index = 0;

	while (pos != -1) // 函数find_first_of() 查找在字符串中第1个出现的字符 ' '，返回匹配的位置。如果没有找到，则函数返回 -1.
	{
		pos = str.find_first_of(' ', index);     //找到空格所在位置   		
		StrWord.push_back(str.substr(index, pos - index));   // 获得字符串str中从第i位开始的长度为pos - i的字符串
		index = pos + 1;
	}
#pragma endregion  

	if (Pattern.size() != StrWord.size())     //如果规则和单词个数不是对应的，直接返回为假
		return false;
	//
	for (unsigned int i = 0; i<Pattern.size(); i++)
	{
		if (PtoW_map.find(Pattern[i]) != PtoW_map.end())   //如果规则表中找到当前规则
		{
			if (PtoW_map[Pattern[i]] == StrWord[i])        //  判断当前规则对应的单词与原位置的单词是否匹配
				continue;
			else
				return false;
		}
		else      //如果规则表中找不到当前规则，将对应规则与单词存入表中
		{
			if (WtoP_map.find(StrWord[i]) != WtoP_map.end())   // 如果找不到规则，但是单词表中出现了，则直接返回false
				return false;

			PtoW_map[Pattern[i]] = StrWord[i];     //将单词存入表中对应的规则下
			WtoP_map[StrWord[i]] = Pattern[i];     //将单词存入单词查找表中
		}
	}
	return true;
}
