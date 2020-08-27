#include "stdafx.h"
#define FILEPATH_Test23 "..//RestoreIpAddresses.ini"     //测试文件地址
void Test23(CString Title)
{
	////  获取样例个数	
	int TestNum = GetPrivateProfileInt(Title, TestNumKey, 0, FILEPATH_Test23);

	CString TitleFind, InputFind, OutputFind;  //测试样例格式信息
	InputFind = TestInputKey_Input;
	OutputFind = TestOutputKey;

	char SSS[DATASUM_BUFFER];
	for (int i = 0; i < TestNum; i++)   //for 循环测试测试样例	
	{
		_itoa(i + 1, SSS, 10);
		CString index = SSS;
		TitleFind = Title + "_" + index;
#pragma region   读取一组测试样例
		char Iutputstr[GET_INI_MAXSIZE];
		int lenstr = GetPrivateProfileString(TitleFind, InputFind, "DefaultName", Iutputstr, GET_INI_MAXSIZE, FILEPATH_Test23);
		char Outputstr[GET_INI_MAXSIZE];
		int lenip = GetPrivateProfileString(TitleFind, OutputFind, "DefaultName", Outputstr, GET_INI_MAXSIZE, FILEPATH_Test23);
#pragma endregion

#pragma region 		 测试得到的测试数据	
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
	}   //for 循环测试测试样例	
}