#include "stdafx.h"
#define FILEPATH_Test22 "..//Rotate.ini"     //�����ļ���ַ
void Test22(CString Title)
{
	////  ��ȡ��������	
	int TestNum = GetPrivateProfileInt(Title, TestNumKey, 0, FILEPATH_Test22);

	CString TitleFind, NumsInputFind, DeltaInputFind, NumsOutputFind;  //����������ʽ��Ϣ
	NumsInputFind = "Input1";
	DeltaInputFind = "Input2";
	NumsOutputFind = TestOutputKey;

	char SSS[DATASUM_BUFFER];
	for (int i = 0; i < TestNum; i++)   //for ѭ�����Բ�������	
	{
		_itoa(i + 1, SSS, 10);
		CString index = SSS;
		TitleFind = Title + "_" + index;
#pragma region   ��ȡһ���������
		char NumsInputStr[GET_INI_MAXSIZE];          //��������
		int lenNums = GetPrivateProfileString(TitleFind, NumsInputFind, "DefaultName", NumsInputStr, GET_INI_MAXSIZE, FILEPATH_Test22);
		int  DeltaData = GetPrivateProfileInt(TitleFind, DeltaInputFind, 0, FILEPATH_Test22);   //����ֵ
		char NumsOutputStr[GET_INI_MAXSIZE];        //�������
		int lenExNums = GetPrivateProfileString(TitleFind, NumsOutputFind, "DefaultName", NumsOutputStr, GET_INI_MAXSIZE, FILEPATH_Test22);
		
#pragma endregion


#pragma region     
		vector<int>flags;
		vector<int>nums;
		int Numlen = StrToInt_New(NumsInputStr, lenNums, nums, flags);

		vector<int>flags_ex;
		vector<int>ex_num;
		int Exlen = StrToInt_New(NumsOutputStr, lenExNums, ex_num, flags_ex);
 
		int k = DeltaData;
		Rotate(nums, k);
		int Expect_Value, Act_Value;
		for (unsigned int i = 0; i < nums.size(); i++)
		{
			Expect_Value = ex_num[i];
			Act_Value = nums[i];
			Assert::AreEqual(Expect_Value, Act_Value);
		}

#pragma endregion
	}   //for ѭ�����Բ�������	
}