#include "stdafx.h"

void Test6(CString Title)
{
	////  ��ȡ��������	
	int TestNum = GetPrivateProfileInt(Title, TestNumKey, 0, FILEPATH);

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
		int len = GetPrivateProfileString(TitleFind, ArrayFind, "DefaultName", Iutputstr, GET_INI_MAXSIZE, FILEPATH);
		char Outputbool[GET_INI_BOOL];
		GetPrivateProfileString(TitleFind, ValueFind, "DefaultName", Outputbool, GET_INI_BOOL, FILEPATH);
#pragma endregion

#pragma region    ��һ�����ݽ����ַ����ָ�		
		vector<int>nums;
		vector<int>flags;
		if (Iutputstr[0]=='[')
		{
			for (int jj = 0; jj < len; jj++)
			{
				Iutputstr[jj] = Iutputstr[jj + 1];
			}
			len = len - 2;
		}
		int Numlen = StrToInt_New(Iutputstr, len, nums, flags);
#pragma endregion

#pragma region 		 ���Եõ��Ĳ�������		
		bool Expect_Value = (string(Outputbool) == "true");	
		bool Act_Value = ContainsDuplicate(nums);
		Assert::AreEqual(Expect_Value, Act_Value);
#pragma endregion
	}   //for ѭ�����Բ�������	
}