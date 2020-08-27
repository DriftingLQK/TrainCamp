#include "stdafx.h"
#define FILEPATH_25 "..//Partition.ini"     //测试文件地址

void Test25(CString Title)
{
	////  获取样例个数	
	int TestNum = GetPrivateProfileInt(Title, TestNumKey, 0, FILEPATH_25);


	CString TitleFind, InputFind, InputFind_k, OutputFind;  //测试样例格式信息
	InputFind = "Input1";
	InputFind_k = "Input2";
	OutputFind = TestOutputKey;


	char SSS[DATASUM_BUFFER];
	for (int i = 0; i < TestNum; i++)   //for 循环测试测试样例	
	{
		_itoa(i + 1, SSS, 10);
		CString index = SSS;
		TitleFind = Title + "_" + index;

#pragma region   读取一组测试样例  
		char Iutputstr[GET_INI_MAXSIZE];
		int lenInput = GetPrivateProfileString(TitleFind, InputFind, "DefaultName", Iutputstr, GET_INI_MAXSIZE, FILEPATH_25);
		int  Iutput_k = GetPrivateProfileInt(TitleFind, InputFind_k, 0, FILEPATH_25);
		char Outputstr[GET_INI_MAXSIZE];
		int lenOutput = GetPrivateProfileString(TitleFind, OutputFind, "DefaultName", Outputstr, GET_INI_MAXSIZE, FILEPATH_25);

#pragma endregion

#pragma region 		 测试得到的测试数据
		vector<int>nums;
		vector<int>flags;
		int Numlen = StrToInt_New(Iutputstr, lenInput, nums, flags);		
		int k = Iutput_k;
		vector<int>exnums;
		vector<int>exflags;
		int exNumlen = StrToInt_New(Outputstr, lenInput, exnums, exflags);


		void CreateList(ListNode* Head, vector<int> &nums);
		ListNode* Head = NULL;
		Head = new ListNode;
		Head->val = nums[0];
		Head->next = NULL;
		CreateList(Head, nums);

		ListNode* Expect_Head = NULL;
		Expect_Head = new ListNode;
		Expect_Head->val = exnums[0];
		Expect_Head->next = NULL;
		CreateList(Expect_Head, exnums);

		ListNode* Expect_Value = Expect_Head;
		ListNode* Act_Value = Partition(Head, k);

		ListNode* lookAct = Act_Value;
		ListNode* lookExpect = Expect_Value;
		int expect, acture;
		while (lookAct != NULL)
		{
			expect = lookAct->val;
			acture = lookExpect->val;		
			lookAct = lookAct->next;
			lookExpect = lookExpect->next;
			Assert::AreEqual(expect, acture);
		}
		//Assert::AreEqual(Expect_Value, Act_Value);
#pragma endregion
	}   //for 循环测试测试样例	
}

void CreateList(ListNode* Head,vector<int> &nums)
{
	ListNode*p = Head;
	for (unsigned int i = 1; i < nums.size(); ++i) 
	{
		ListNode* pNewNode = new ListNode;
		pNewNode->val = nums[i]; // 将新节点的值赋值
		pNewNode->next = NULL;
		p->next = pNewNode;      // 上一个节点指向这个新建立的节点
		p = pNewNode;            // p节点指向这个新的节点
	}
}