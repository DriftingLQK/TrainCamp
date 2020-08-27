#include "stdafx.h"

void Test9(CString Title)
{
	////  获取样例个数	
	int TestNum = GetPrivateProfileInt(Title, TestNumKey, 0, FILEPATH);

	CString TitleFind, Input1_Find, Input2_Find, ValueFind;  //测试样例格式信息
	Input1_Find = TestInputKey_Input;
	Input1_Find = Input1_Find + '1';
	Input2_Find = TestInputKey_Input;
	Input2_Find = Input2_Find + '2';
	ValueFind = TestOutputKey;

	char SSS[DATASUM_BUFFER];
	for (int i = 0; i < TestNum; i++)   //for 循环测试测试样例	
	{
		_itoa(i + 1, SSS, 10);
		CString index = SSS;
		TitleFind = Title + "_" + index;
#pragma region   读取一组测试样例
		char Iutputstr_1[GET_INI_MAXSIZE];
		GetPrivateProfileString(TitleFind, Input1_Find, "DefaultName", Iutputstr_1, GET_INI_MAXSIZE, FILEPATH);
		char Iutputstr_2[GET_INI_MAXSIZE];
		GetPrivateProfileString(TitleFind, Input2_Find, "DefaultName", Iutputstr_2, GET_INI_MAXSIZE, FILEPATH);
		char Outputstr[GET_INI_MAXSIZE];
		GetPrivateProfileString(TitleFind, ValueFind, "DefaultName", Outputstr, GET_INI_MAXSIZE, FILEPATH);
#pragma endregion

#pragma region 		 测试得到的测试数据

		string Expect_Value = Outputstr;
		string Act_Value = AddBinary(Iutputstr_1, Iutputstr_2);
		Assert::AreEqual(Expect_Value, Act_Value);
#pragma endregion
	}   //for 循环测试测试样例	
}