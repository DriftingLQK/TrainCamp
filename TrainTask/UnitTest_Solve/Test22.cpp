#include "stdafx.h"
#define FILEPATH_Test22 "..//Rotate.ini"     //测试文件地址
void Test22(CString Title)
{
	////  获取样例个数	
	int TestNum = GetPrivateProfileInt(Title, TestNumKey, 0, FILEPATH_Test22);

	CString TitleFind, NumsInputFind, DeltaInputFind, NumsOutputFind;  //测试样例格式信息
	NumsInputFind = "Input1";
	DeltaInputFind = "Input2";
	NumsOutputFind = TestOutputKey;

	char SSS[DATASUM_BUFFER];
	for (int i = 0; i < TestNum; i++)   //for 循环测试测试样例	
	{
		_itoa(i + 1, SSS, 10);
		CString index = SSS;
		TitleFind = Title + "_" + index;
#pragma region   读取一组测试样例
		char NumsInputStr[GET_INI_MAXSIZE];          //给定数组
		int lenNums = GetPrivateProfileString(TitleFind, NumsInputFind, "DefaultName", NumsInputStr, GET_INI_MAXSIZE, FILEPATH_Test22);
		int  DeltaData = GetPrivateProfileInt(TitleFind, DeltaInputFind, 0, FILEPATH_Test22);   //距离值
		char NumsOutputStr[GET_INI_MAXSIZE];        //期望结果
		int lenExNums = GetPrivateProfileString(TitleFind, NumsOutputFind, "DefaultName", NumsOutputStr, GET_INI_MAXSIZE, FILEPATH_Test22);
		
#pragma endregion


#pragma region     
		vector<int>flags;
		vector<int>nums;
		int Numlen = StrToInt_New(NumsInputStr, lenNums, nums, flags);

		vector<int>flags_ex;
		vector<int>ex_num;
		int Exlen = StrToInt_New(NumsOutputStr, lenExNums, ex_num, flags_ex);
 
		int k = DeltaData;
		Rotate(nums, k);
		int Expect_Value, Act_Value;
		for (unsigned int i = 0; i < nums.size(); i++)
		{
			Expect_Value = ex_num[i];
			Act_Value = nums[i];
			Assert::AreEqual(Expect_Value, Act_Value);
		}

#pragma endregion
	}   //for 循环测试测试样例	
}