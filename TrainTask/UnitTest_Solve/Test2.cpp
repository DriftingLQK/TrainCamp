#include "stdafx.h"


void Test2(CString Title)
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
		char Outputbool[GET_INI_BOOL];
		GetPrivateProfileString(TitleFind, OutputFind, "DefaultName", Outputbool, GET_INI_BOOL, FILEPATH);
#pragma endregion

#pragma region 		 ���Եõ��Ĳ�������
		string Expect_Value = Outputbool;
		string Act_Value = ExcelSheetColumnTitle(InputData);
		Assert::AreEqual(Expect_Value, Act_Value);
#pragma endregion
	}   //for ѭ�����Բ�������	
}