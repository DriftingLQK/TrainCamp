#include "stdafx.h"
#define FILEPATH_14 "..//LengthOfLongestSubstring.ini"     //�����ļ���ַ

void Test24(CString Title)
{
	////  ��ȡ��������	
	int TestNum = GetPrivateProfileInt(Title, TestNumKey, 0, FILEPATH_14);


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
		char Iutputstr[GET_INI_MAXSIZE];
		int lenInput = GetPrivateProfileString(TitleFind, InputFind, "DefaultName", Iutputstr, GET_INI_MAXSIZE, FILEPATH_14);
		int  OutputData = GetPrivateProfileInt(TitleFind, OutputFind, 0, FILEPATH_14);
#pragma endregion

#pragma region 		 ���Եõ��Ĳ�������
		char *s = Iutputstr;
		int Expect_Value = OutputData;
		int Act_Value = LengthOfLongestSubstring(Iutputstr);
		Assert::AreEqual(Expect_Value, Act_Value);
#pragma endregion
	}   //for ѭ�����Բ�������	
}