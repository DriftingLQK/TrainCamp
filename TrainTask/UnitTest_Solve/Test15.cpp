#include "stdafx.h"
#define FILEPATH_Test15 "..//WordPattern.ini"     //测试文件地址
void Test15(CString Title)
{
	////  获取样例个数	
	int TestNum = GetPrivateProfileInt(Title, TestNumKey, 0, FILEPATH_Test15);

	CString TitleFind, PatternInput, StrInput, ValueFind;  //测试样例格式信息
	PatternInput = "Pattern ";
	StrInput = "Str";
	ValueFind = TestOutputKey;

	char SSS[DATASUM_BUFFER];
	for (int i = 0; i < TestNum; i++)   //for 循环测试测试样例	
	{
		_itoa(i + 1, SSS, 10);
		CString index = SSS;
		TitleFind = Title + "_" + index;
#pragma region   读取一组测试样例
		char IutputPattern[GET_INI_MAXSIZE];
		int lenPattern = GetPrivateProfileString(TitleFind, PatternInput, "DefaultName", IutputPattern, GET_INI_MAXSIZE, FILEPATH_Test15);
		char IutputStr[GET_INI_MAXSIZE];
		int lenStr = GetPrivateProfileString(TitleFind, StrInput, "DefaultName", IutputStr, GET_INI_MAXSIZE, FILEPATH_Test15);
		char Outputbool[GET_INI_BOOL];
		GetPrivateProfileString(TitleFind, ValueFind, "DefaultName", Outputbool, GET_INI_BOOL, FILEPATH_Test15);
#pragma endregion

#pragma region 		 测试得到的测试数据		
		bool Expect_Value = (string(Outputbool) == "true");
		bool Act_Value = WordPattern(IutputPattern, IutputStr);
		Assert::AreEqual(Expect_Value, Act_Value);
#pragma endregion
	}   //for 循环测试测试样例	
}