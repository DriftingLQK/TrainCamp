#include "stdafx.h"

void Test10(CString Title)
{
	////  获取样例个数	
	int TestNum = GetPrivateProfileInt(Title, TestNumKey, 0, FILEPATH);

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
		char Inputstr[GET_INI_MAXSIZE];
		int len = GetPrivateProfileString(TitleFind, InputFind, "DefaultName", Inputstr, GET_INI_MAXSIZE, FILEPATH);
		char  Onputstr[GET_INI_MAXSIZE];
		int lenpath;
		lenpath = GetPrivateProfileString(TitleFind, OutputFind, "DefaultName", Onputstr, GET_INI_MAXSIZE, FILEPATH);
    
		vector<int>nums;// 读取到的测试数据（字符串）
		vector<int>flags;
		int Numlen = StrToInt_New(Inputstr, len, nums, flags);

		int start = 0;
		TreeNode* root = NULL;
		root = CreateBTree(root, nums, flags, Numlen, start);
#pragma endregion

#pragma region 		 测试得到的测试数据

		vector<string>ExpectPaths;
		int begin = 0;
		int temp=0 ;
		for (temp; temp <lenpath; temp++)
		{
			char cc = Onputstr[temp];
			if (Onputstr[temp] == ',')
			{
				string p;
				for (int j = begin; j < temp - 1; j++)
				{
					p = p + Onputstr[j];

				}
				begin = temp + 2;
				ExpectPaths.push_back(p);
			}

		}
		if (temp == lenpath)
		{
			string p;
			for (int j = begin; j < temp; j++)
			{
				p = p + Onputstr[j];

			}
			ExpectPaths.push_back(p);
		}

		vector<string>ActPath;		
		ActPath = BinaryTreePaths(root);
		for (unsigned int i = 0; i < ActPath.size(); i++)
		{
			string actstr = ActPath[i];
			string expstr = ExpectPaths[i];
			Assert::AreEqual(ExpectPaths[i], ActPath[i]);
		}
		
#pragma endregion
	}   //for 循环测试测试样例	
}