#include "stdafx.h"

void Test8(CString Title)
{
	////  获取样例个数	
	int TestNum = GetPrivateProfileInt(Title, TestNumKey, 0, FILEPATH);

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
		int InputData = GetPrivateProfileInt(TitleFind, InputFind, 0, FILEPATH);
		int OutputValue = GetPrivateProfileInt(TitleFind, OutputFind, 0, FILEPATH);
#pragma endregion

#pragma region 		 测试得到的测试数据
		int Expect_Value = OutputValue;
		int Act_Value = HammingWeight(InputData);
		Assert::AreEqual(Expect_Value, Act_Value);
#pragma endregion
	}   //for 循环测试测试样例	
}