#include "stdafx.h"
#define FILEPATH_Test17 "..//WordBreak.ini"     //�����ļ���ַ
void Test17(CString Title)
{
	////  ��ȡ��������	
	int TestNum = GetPrivateProfileInt(Title, TestNumKey, 0, FILEPATH_Test17);

	CString TitleFind, WordsInput, StrInput, ValueFind;  //����������ʽ��Ϣ
	StrInput = "Input1";
	WordsInput = "Input2";
	ValueFind = TestOutputKey;

	char SSS[DATASUM_BUFFER];
	for (int i = 0; i < TestNum; i++)   //for ѭ�����Բ�������	
	{
		_itoa(i + 1, SSS, 10);
		CString index = SSS;
		TitleFind = Title + "_" + index;
#pragma region   ��ȡһ���������
		char IutputStr[GET_INI_MAXSIZE];
		int lenStr = GetPrivateProfileString(TitleFind, StrInput, "DefaultName", IutputStr, GET_INI_MAXSIZE, FILEPATH_Test17);
		char IutputWords[GET_INI_MAXSIZE];
		int lenWords = GetPrivateProfileString(TitleFind, WordsInput, "DefaultName", IutputWords, GET_INI_MAXSIZE, FILEPATH_Test17);
		char Outputbool[GET_INI_BOOL];
		GetPrivateProfileString(TitleFind, ValueFind, "DefaultName", Outputbool, GET_INI_BOOL, FILEPATH_Test17);
#pragma endregion

#pragma region 		 ���Եõ��Ĳ�������		
		vector<string>wordDict;//�洢������
#pragma region     �Ƚ��ַ����Կո�������洢��������
		int pos = 0;
		int start = 0;
		string str = IutputWords;
		while (pos != -1) // ����find_first_of() �������ַ����е�1�����ֵ��ַ� ' '������ƥ���λ�á����û���ҵ����������� -1.
		{
			pos = str.find_first_of(',', start);     //�ҵ��ո�����λ��   		
			wordDict.push_back(str.substr(start, pos - start));   // ����ַ���str�дӵ�iλ��ʼ�ĳ���Ϊpos - i���ַ���
			start = pos + 1;
		}
#pragma endregion  

		bool Expect_Value = (string(Outputbool) == "true");
		bool Act_Value = WordBreak(IutputStr, wordDict);
		Assert::AreEqual(Expect_Value, Act_Value);
#pragma endregion
	}   //for ѭ�����Բ�������	
}