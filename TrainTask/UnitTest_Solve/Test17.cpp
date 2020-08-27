#include "stdafx.h"
#define FILEPATH_Test17 "..//WordBreak.ini"     //测试文件地址
void Test17(CString Title)
{
	////  获取样例个数	
	int TestNum = GetPrivateProfileInt(Title, TestNumKey, 0, FILEPATH_Test17);

	CString TitleFind, WordsInput, StrInput, ValueFind;  //测试样例格式信息
	StrInput = "Input1";
	WordsInput = "Input2";
	ValueFind = TestOutputKey;

	char SSS[DATASUM_BUFFER];
	for (int i = 0; i < TestNum; i++)   //for 循环测试测试样例	
	{
		_itoa(i + 1, SSS, 10);
		CString index = SSS;
		TitleFind = Title + "_" + index;
#pragma region   读取一组测试样例
		char IutputStr[GET_INI_MAXSIZE];
		int lenStr = GetPrivateProfileString(TitleFind, StrInput, "DefaultName", IutputStr, GET_INI_MAXSIZE, FILEPATH_Test17);
		char IutputWords[GET_INI_MAXSIZE];
		int lenWords = GetPrivateProfileString(TitleFind, WordsInput, "DefaultName", IutputWords, GET_INI_MAXSIZE, FILEPATH_Test17);
		char Outputbool[GET_INI_BOOL];
		GetPrivateProfileString(TitleFind, ValueFind, "DefaultName", Outputbool, GET_INI_BOOL, FILEPATH_Test17);
#pragma endregion

#pragma region 		 测试得到的测试数据		
		vector<string>wordDict;//存储各单词
#pragma region     先将字符串以空格隔开，存储到向量中
		int pos = 0;
		int start = 0;
		string str = IutputWords;
		while (pos != -1) // 函数find_first_of() 查找在字符串中第1个出现的字符 ' '，返回匹配的位置。如果没有找到，则函数返回 -1.
		{
			pos = str.find_first_of(',', start);     //找到空格所在位置   		
			wordDict.push_back(str.substr(start, pos - start));   // 获得字符串str中从第i位开始的长度为pos - i的字符串
			start = pos + 1;
		}
#pragma endregion  

		bool Expect_Value = (string(Outputbool) == "true");
		bool Act_Value = WordBreak(IutputStr, wordDict);
		Assert::AreEqual(Expect_Value, Act_Value);
#pragma endregion
	}   //for 循环测试测试样例	
}