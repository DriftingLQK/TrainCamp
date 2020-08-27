#include "stdafx.h"
#define FILEPATH_Test20 "..//MoveZeroes.ini"     //测试文件地址
void Test20(CString Title)
{
	////  获取样例个数	
	int TestNum = GetPrivateProfileInt(Title, TestNumKey, 0, FILEPATH_Test20);

	CString TitleFind, InputFind, OutputFind;  //测试样例格式信息
	InputFind = TestInputKey_Input;
	OutputFind = TestOutputKey;

	char SSS[DATASUM_BUFFER];
	for (int i = 0; i < TestNum; i++)   //for 循环测试测试样例	
	{
		_itoa(i + 1, SSS, 10);
		CString index = SSS;
		TitleFind = Title + "_" + index;
#pragma region   读取一组测试样例
		char Iutputstr[GET_INI_MAXSIZE];
		int lennum = GetPrivateProfileString(TitleFind, InputFind, "DefaultName", Iutputstr, GET_INI_MAXSIZE, FILEPATH_Test20);
		char Outputstr[GET_INI_MAXSIZE];
		int lenex = GetPrivateProfileString(TitleFind, OutputFind, "DefaultName", Outputstr, GET_INI_MAXSIZE, FILEPATH_Test20);
#pragma endregion

#pragma region 		 测试得到的测试数据	
		vector<int>flags;
		vector<int>nums;
		int Numlen = StrToInt_New(Iutputstr, lennum, nums, flags);

		vector<int>flags_ex;
		vector<int>ex_num;
		int Exlen = StrToInt_New(Outputstr, lenex, ex_num, flags_ex);

		MoveZeroes(nums);
		int Act_Value, Expect_Value;
		for (unsigned int i = 0; i < nums.size(); i++)
		{
			Act_Value = nums[i];
			Expect_Value = ex_num[i];
			Assert::AreEqual(Expect_Value, Act_Value);
		}


#pragma endregion
	}   //for 循环测试测试样例	
}