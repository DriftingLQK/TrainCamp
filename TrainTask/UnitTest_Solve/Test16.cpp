#include "stdafx.h"
#define FILEPATH_16 "..//ReverseBits.ini"     //�����ļ���ַ

void Test16(CString Title)
{
	////  ��ȡ��������	
	int TestNum = GetPrivateProfileInt(Title, TestNumKey, 0, FILEPATH_16);


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
		unsigned int  InputData = GetPrivateProfileInt(TitleFind, InputFind, 0, FILEPATH_16);
		unsigned int  OutputData = GetPrivateProfileInt(TitleFind, OutputFind, 0, FILEPATH_16);
#pragma endregion

#pragma region 		 ���Եõ��Ĳ�������		
		unsigned int Expect_Value = OutputData;
		unsigned int Act_Value = ReverseBits((unsigned int)InputData);
		Assert::AreEqual(Expect_Value, Act_Value);
#pragma endregion
	}   //for ѭ�����Բ�������	
}