#include "stdafx.h"

void Test9(CString Title)
{
	////  ��ȡ��������	
	int TestNum = GetPrivateProfileInt(Title, TestNumKey, 0, FILEPATH);

	CString TitleFind, Input1_Find, Input2_Find, ValueFind;  //����������ʽ��Ϣ
	Input1_Find = TestInputKey_Input;
	Input1_Find = Input1_Find + '1';
	Input2_Find = TestInputKey_Input;
	Input2_Find = Input2_Find + '2';
	ValueFind = TestOutputKey;

	char SSS[DATASUM_BUFFER];
	for (int i = 0; i < TestNum; i++)   //for ѭ�����Բ�������	
	{
		_itoa(i + 1, SSS, 10);
		CString index = SSS;
		TitleFind = Title + "_" + index;
#pragma region   ��ȡһ���������
		char Iutputstr_1[GET_INI_MAXSIZE];
		GetPrivateProfileString(TitleFind, Input1_Find, "DefaultName", Iutputstr_1, GET_INI_MAXSIZE, FILEPATH);
		char Iutputstr_2[GET_INI_MAXSIZE];
		GetPrivateProfileString(TitleFind, Input2_Find, "DefaultName", Iutputstr_2, GET_INI_MAXSIZE, FILEPATH);
		char Outputstr[GET_INI_MAXSIZE];
		GetPrivateProfileString(TitleFind, ValueFind, "DefaultName", Outputstr, GET_INI_MAXSIZE, FILEPATH);
#pragma endregion

#pragma region 		 ���Եõ��Ĳ�������

		string Expect_Value = Outputstr;
		string Act_Value = AddBinary(Iutputstr_1, Iutputstr_2);
		Assert::AreEqual(Expect_Value, Act_Value);
#pragma endregion
	}   //for ѭ�����Բ�������	
}