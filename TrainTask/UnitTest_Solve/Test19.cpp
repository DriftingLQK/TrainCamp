#include "stdafx.h"
#define FILEPATH_19 "..//Sqrt.ini"     //�����ļ���ַ

void Test19(CString Title)
{
	////  ��ȡ��������	
	int TestNum = GetPrivateProfileInt(Title, TestNumKey, 0, FILEPATH_19);


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
		int  InputData = GetPrivateProfileInt(TitleFind, InputFind, 0, FILEPATH_19);
		int  OutputData = GetPrivateProfileInt(TitleFind, OutputFind, 0, FILEPATH_19);
#pragma endregion

#pragma region 		 ���Եõ��Ĳ�������		
		int Expect_Value = OutputData;
		int Act_Value = Sqrt(InputData);
		Assert::AreEqual(Expect_Value, Act_Value);
#pragma endregion
	}   //for ѭ�����Բ�������	
}