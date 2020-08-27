#include "stdafx.h"
#define FILEPATH_Test15 "..//WordPattern.ini"     //�����ļ���ַ
void Test15(CString Title)
{
	////  ��ȡ��������	
	int TestNum = GetPrivateProfileInt(Title, TestNumKey, 0, FILEPATH_Test15);

	CString TitleFind, PatternInput, StrInput, ValueFind;  //����������ʽ��Ϣ
	PatternInput = "Pattern ";
	StrInput = "Str";
	ValueFind = TestOutputKey;

	char SSS[DATASUM_BUFFER];
	for (int i = 0; i < TestNum; i++)   //for ѭ�����Բ�������	
	{
		_itoa(i + 1, SSS, 10);
		CString index = SSS;
		TitleFind = Title + "_" + index;
#pragma region   ��ȡһ���������
		char IutputPattern[GET_INI_MAXSIZE];
		int lenPattern = GetPrivateProfileString(TitleFind, PatternInput, "DefaultName", IutputPattern, GET_INI_MAXSIZE, FILEPATH_Test15);
		char IutputStr[GET_INI_MAXSIZE];
		int lenStr = GetPrivateProfileString(TitleFind, StrInput, "DefaultName", IutputStr, GET_INI_MAXSIZE, FILEPATH_Test15);
		char Outputbool[GET_INI_BOOL];
		GetPrivateProfileString(TitleFind, ValueFind, "DefaultName", Outputbool, GET_INI_BOOL, FILEPATH_Test15);
#pragma endregion

#pragma region 		 ���Եõ��Ĳ�������		
		bool Expect_Value = (string(Outputbool) == "true");
		bool Act_Value = WordPattern(IutputPattern, IutputStr);
		Assert::AreEqual(Expect_Value, Act_Value);
#pragma endregion
	}   //for ѭ�����Բ�������	
}