#include "stdafx.h"

void Test1(CString Title)
{
	////  ��ȡ��������	
	int TestNum = GetPrivateProfileInt(Title, TestNumKey, 0, FILEPATH);

	CString TitleFind, ArrayFind, KeyFind, ValueFind;  //����������ʽ��Ϣ
	ArrayFind = TestInputArray;
	KeyFind = TestInputKey;
	ValueFind = TestOutputKey;

	char SSS[DATASUM_BUFFER];
	for (int i = 0; i < TestNum; i++)   //for ѭ�����Բ�������	
	{
		_itoa(i+ 1, SSS, 10);
		CString index = SSS;
		TitleFind = Title +"_"+ index;
#pragma region   ��ȡһ���������
		char Iutputstr[GET_INI_MAXSIZE];
		int len = GetPrivateProfileString(TitleFind, ArrayFind, "DefaultName", Iutputstr, GET_INI_MAXSIZE, FILEPATH);
		int key = GetPrivateProfileInt(TitleFind, KeyFind, 0, FILEPATH);
		char Outputbool[GET_INI_BOOL];
		GetPrivateProfileString(TitleFind, ValueFind, "DefaultName", Outputbool, GET_INI_BOOL, FILEPATH);
#pragma endregion

#pragma region    ��һ�����ݽ����ַ����ָ�
		vector<int>nums;
		vector<int>flags;   
		int Numlen = StrToInt_New(Iutputstr, len, nums, flags);
#pragma endregion

#pragma region 		 ���Եõ��Ĳ�������
		
		int k = key;
		bool Expect_Value = (string(Outputbool) == "true");		
		bool Act_Value = ContainsNearbyDuplicate(nums, k);
		Assert::AreEqual(Expect_Value, Act_Value);
#pragma endregion
	}   //for ѭ�����Բ�������	
}