#include "stdafx.h"

void Test10(CString Title)
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
		char Inputstr[GET_INI_MAXSIZE];
		int len = GetPrivateProfileString(TitleFind, InputFind, "DefaultName", Inputstr, GET_INI_MAXSIZE, FILEPATH);
		char  Onputstr[GET_INI_MAXSIZE];
		int lenpath;
		lenpath = GetPrivateProfileString(TitleFind, OutputFind, "DefaultName", Onputstr, GET_INI_MAXSIZE, FILEPATH);
    
		vector<int>nums;// ��ȡ���Ĳ������ݣ��ַ�����
		vector<int>flags;
		int Numlen = StrToInt_New(Inputstr, len, nums, flags);

		int start = 0;
		TreeNode* root = NULL;
		root = CreateBTree(root, nums, flags, Numlen, start);
#pragma endregion

#pragma region 		 ���Եõ��Ĳ�������

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
	}   //for ѭ�����Բ�������	
}