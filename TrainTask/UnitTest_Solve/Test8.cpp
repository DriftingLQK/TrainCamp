#include "stdafx.h"

void Test8(CString Title)
{
	////  ��ȡ��������	
	int TestNum = GetPrivateProfileInt(Title, TestNumKey, 0, FILEPATH);

	CString TitleFind, InputFind, OutputFind;  //����������ʽ��Ϣ
	InputFind = TestInputKey_Input;
	OutputFind = TestOutputKey;

	char SSS[DATASUM_BUFFER];
	for (int i = 0; i < TestNum; i++)   //for ѭ�����Բ�������	 
	{
		_itoa(i + 1, SSS, 10);
		CString index = SSS;
		TitleFind = Title + "_" + index;

#pragma region   ��ȡһ���������
		int InputData = GetPrivateProfileInt(TitleFind, InputFind, 0, FILEPATH);
		int OutputValue = GetPrivateProfileInt(TitleFind, OutputFind, 0, FILEPATH);
#pragma endregion

#pragma region 		 ���Եõ��Ĳ�������
		int Expect_Value = OutputValue;
		int Act_Value = HammingWeight(InputData);
		Assert::AreEqual(Expect_Value, Act_Value);
#pragma endregion
	}   //for ѭ�����Բ�������	
}