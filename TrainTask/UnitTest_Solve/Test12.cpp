#include "stdafx.h"
#define FILEPATH_Test12 "..//IsValid.ini"     //�����ļ���ַ
void Test12(CString Title)
{
	////  ��ȡ��������	
	int TestNum = GetPrivateProfileInt(Title, TestNumKey, 0, FILEPATH_Test12);

	CString TitleFind, ArrayFind, ValueFind;  //����������ʽ��Ϣ
	ArrayFind = TestInputKey_Input;
	ValueFind = TestOutputKey;

	char SSS[DATASUM_BUFFER];
	for (int i = 0; i < TestNum; i++)   //for ѭ�����Բ�������	
	{
		_itoa(i + 1, SSS, 10);
		CString index = SSS;
		TitleFind = Title + "_" + index;
#pragma region   ��ȡһ���������
		char Iutputstr[GET_INI_MAXSIZE];
		int len = GetPrivateProfileString(TitleFind, ArrayFind, "DefaultName", Iutputstr, GET_INI_MAXSIZE, FILEPATH_Test12);
		char Outputbool[GET_INI_BOOL];
		GetPrivateProfileString(TitleFind, ValueFind, "DefaultName", Outputbool, GET_INI_BOOL, FILEPATH_Test12);
#pragma endregion

#pragma region 		 ���Եõ��Ĳ�������		
		bool Expect_Value = (string(Outputbool) == "true");
		bool Act_Value = IsValid(Iutputstr);
		Assert::AreEqual(Expect_Value, Act_Value);
#pragma endregion
	}   //for ѭ�����Բ�������	
}