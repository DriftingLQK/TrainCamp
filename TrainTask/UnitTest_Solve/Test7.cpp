#include "stdafx.h"

void Test7(CString Title)
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
		char Inputstr[GET_INI_BOOL];
		int len =GetPrivateProfileString(TitleFind, InputFind, "DefaultName", Inputstr, GET_INI_BOOL, FILEPATH);
		int OnputData = GetPrivateProfileInt(TitleFind, OutputFind, 0, FILEPATH);

		//int InputData[GET_INI_MAXSIZE];            // ��ȡ���Ĳ������ݣ��ַ�����
		//int CheckData[GET_INI_MAXSIZE];
		//CheckData[0] = 0;
		//int Numlen = Str_To_Int(Inputstr, InputData, CheckData, GET_INI_MAXSIZE);

		vector<int>nums;
		vector<int>flags;
		int Numlen = StrToInt_New(Inputstr, len, nums, flags);

		int start = 0;
		TreeNode* root = NULL;
		root = CreateBTree(root, nums, flags, Numlen, start);
#pragma endregion

#pragma region 		 ���Եõ��Ĳ�������
		int Expect_Value = OnputData;
		int Act_Value = MaxDepth(root);
		Assert::AreEqual(Expect_Value, Act_Value);
#pragma endregion
	}   //for ѭ�����Բ�������	
}