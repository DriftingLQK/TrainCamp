#include "stdafx.h"
#define FILEPATH_Test23 "..//RestoreIpAddresses.ini"     //�����ļ���ַ
void Test23(CString Title)
{
	////  ��ȡ��������	
	int TestNum = GetPrivateProfileInt(Title, TestNumKey, 0, FILEPATH_Test23);

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
		int lenstr = GetPrivateProfileString(TitleFind, InputFind, "DefaultName", Iutputstr, GET_INI_MAXSIZE, FILEPATH_Test23);
		char Outputstr[GET_INI_MAXSIZE];
		int lenip = GetPrivateProfileString(TitleFind, OutputFind, "DefaultName", Outputstr, GET_INI_MAXSIZE, FILEPATH_Test23);
#pragma endregion

#pragma region 		 ���Եõ��Ĳ�������	
		vector<string>exIpPath;
		int begin = 0;
		int temp = 0;
		for (temp; temp <lenip; temp++)
		{
			char cc = Outputstr[temp];
			if (Outputstr[temp] == ',')
			{
				string p;
				for (int j = begin; j < temp - 1; j++)
				{
					p = p + Outputstr[j];

				}
				begin = temp + 2;
				exIpPath.push_back(p);
			}

		}
		if (temp == lenip)
		{
			string p;
			for (int j = begin; j < temp; j++)
			{
				p = p + Outputstr[j];

			}
			exIpPath.push_back(p);
		}
		
		string inputIp = Iutputstr;
		vector<string >IpPath = RestoreIpAddresses(inputIp);
		string Act_Value, Expect_Value;
		for (unsigned int i = 0; i < IpPath.size(); i++)
		{
			Act_Value = IpPath[i];
			Expect_Value = exIpPath[i];
			Assert::AreEqual(Expect_Value, Act_Value);
		}


#pragma endregion
	}   //for ѭ�����Բ�������	
}