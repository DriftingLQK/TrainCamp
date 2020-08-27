#include "stdafx.h"

void Test1(CString Title)
{
	////  获取样例个数	
	int TestNum = GetPrivateProfileInt(Title, TestNumKey, 0, FILEPATH);

	CString TitleFind, ArrayFind, KeyFind, ValueFind;  //测试样例格式信息
	ArrayFind = TestInputArray;
	KeyFind = TestInputKey;
	ValueFind = TestOutputKey;

	char SSS[DATASUM_BUFFER];
	for (int i = 0; i < TestNum; i++)   //for 循环测试测试样例	
	{
		_itoa(i+ 1, SSS, 10);
		CString index = SSS;
		TitleFind = Title +"_"+ index;
#pragma region   读取一组测试样例
		char Iutputstr[GET_INI_MAXSIZE];
		int len = GetPrivateProfileString(TitleFind, ArrayFind, "DefaultName", Iutputstr, GET_INI_MAXSIZE, FILEPATH);
		int key = GetPrivateProfileInt(TitleFind, KeyFind, 0, FILEPATH);
		char Outputbool[GET_INI_BOOL];
		GetPrivateProfileString(TitleFind, ValueFind, "DefaultName", Outputbool, GET_INI_BOOL, FILEPATH);
#pragma endregion

#pragma region    对一组数据进行字符串分割
		vector<int>nums;
		vector<int>flags;   
		int Numlen = StrToInt_New(Iutputstr, len, nums, flags);
#pragma endregion

#pragma region 		 测试得到的测试数据
		
		int k = key;
		bool Expect_Value = (string(Outputbool) == "true");		
		bool Act_Value = ContainsNearbyDuplicate(nums, k);
		Assert::AreEqual(Expect_Value, Act_Value);
#pragma endregion
	}   //for 循环测试测试样例	
}