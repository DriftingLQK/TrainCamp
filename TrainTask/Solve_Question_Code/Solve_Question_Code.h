

#ifndef __SOLVE_QUESTION_CODE_H
#define __SOLVE_QUESTION_CODE_H

#ifdef DLL_Provider
#define HEAD_DLL __declspec(dllexport)
#else
#define HEAD_DLL __declspec(dllimport)
#endif

using namespace std;


#include <vector>   // 使用容器关键头文件

 //二叉树结构体建立
struct TreeNode {         
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
 //链表结构体建立
struct ListNode
{
	int val;
	ListNode *next;
	//ListNode(int x) : val(x), next(NULL) {}
};

HEAD_DLL bool ContainsNearbyDuplicate(vector<int>&, int);       //第一题
HEAD_DLL string ExcelSheetColumnTitle(int n);                   //第二题
HEAD_DLL bool IsUgly(int num);									//第三题
HEAD_DLL bool IsPalindrome(int x);								//第四题
HEAD_DLL int MinDepth(TreeNode* root);							//第五题
HEAD_DLL bool ContainsDuplicate(vector<int>& nums);				//第六题
HEAD_DLL int MaxDepth(TreeNode* root);							//第七题
HEAD_DLL int HammingWeight(unsigned int n);						//第八题
HEAD_DLL string AddBinary(string a, string b);					//第九题
HEAD_DLL vector<string> BinaryTreePaths(TreeNode* root);		//第十题
HEAD_DLL bool NimGame(int n);									//第十一题
HEAD_DLL bool IsValid(string str);								//第十二题
HEAD_DLL int myAtoi(string str);								//第十三题
HEAD_DLL int SingleNumber(vector<int>& nums);					//第十四题
HEAD_DLL bool WordPattern(string Pattern, string str);			//第十五题
HEAD_DLL unsigned int ReverseBits(unsigned int n);				//第十六题
HEAD_DLL bool WordBreak(string str, vector<string>& wordDict);  //第十七题
HEAD_DLL vector<int> PlusOne(vector<int>& digits);              //第十八题
HEAD_DLL int Sqrt(int y);                                       //第十九题
HEAD_DLL void MoveZeroes(vector<int>& nums);                    //第二十题
HEAD_DLL int Reverse(int x);                                    //第二十一题
HEAD_DLL void Rotate(vector<int>& nums, int k);                 //第二十二题
HEAD_DLL vector<string> RestoreIpAddresses(string s);           //第二十三题
HEAD_DLL int LengthOfLongestSubstring(char * s);                //第二十四题
HEAD_DLL ListNode* Partition(ListNode* head, int x);            //第二十五题
#endif

