#include<iostream>
#include<vector>
#include<string>
using namespace std;

/************************第十七题*****************
[要求]
给定一个非空字符串s和一个包含非空单词列表的字典wordDict，
判定s是否可以被空格拆分为一个或多个在字典中出现的单词
******************************************************/



//根据字典单词判断字符串是否从当前位置匹配，判断可拆分的位置，依次判断可拆分位置的后续字符串是否匹配
bool WordBreak(string str, vector<string>& wordDict)
{
	int len = str.size();
	if (len <= 0 || wordDict.size() == 0)
	{
		return false;
	}
	vector<bool> Check(len + 1, false);     //创建一个vector 大小为len+1，值全为false
	Check[0] = true;   //表示从起始位置开始可以进行匹配

	for (int index = 0; index < len; index++)    //遍历字符串的各个字符
	{
		if (Check[index] == false)
			continue;
		for (string word : wordDict)     //遍历字典中的各个单词 
		{
			if (str.find(word, index) == index)   //判断 字典中的各个字符串能否在当前位置找到对应的
				Check[index + (int)word.size()] = true;
		}
	}
	return Check[len];
}

//bool WordBreak(string s, vector<string>& wordDict)   //根据字典单词长度判断字符串是否匹配
//{
//	int len = s.size();
//	if (len <= 0 || wordDict.size() == 0)
//	{
//		return false;
//	}
//	vector<int>Check(len + 1, false);  //创建一个容器
//	Check[0] = true;
//	int wordstart = NULL;
//	string strword;
//	for (unsigned int i = 1; i < s.size() + 1; ++i)
//	{
//		for (string word : wordDict)
//		{
//			wordstart = i - word.size();                 //单词起始位置
//			if (i >= word.size() && Check[wordstart])
//			{
//				strword = s.substr(wordstart, word.size());  //截取字符串中对应长度的单词
//				if (word == strword)
//				{
//					Check[i] = true;
//					break;
//				}
//			}
//		}
//	}
//	return Check[len];
//	//return *Check.rbegin();   //rbegin() 指向反向的第一个元素  end 指向正向最后一个元素+1的位置
//}