

#ifndef __SOLVE_QUESTION_CODE_H
#define __SOLVE_QUESTION_CODE_H

#ifdef DLL_Provider
#define HEAD_DLL __declspec(dllexport)
#else
#define HEAD_DLL __declspec(dllimport)
#endif

using namespace std;


#include <vector>   // ʹ�������ؼ�ͷ�ļ�

 //�������ṹ�彨��
struct TreeNode {         
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
 //����ṹ�彨��
struct ListNode
{
	int val;
	ListNode *next;
	//ListNode(int x) : val(x), next(NULL) {}
};

HEAD_DLL bool ContainsNearbyDuplicate(vector<int>&, int);       //��һ��
HEAD_DLL string ExcelSheetColumnTitle(int n);                   //�ڶ���
HEAD_DLL bool IsUgly(int num);									//������
HEAD_DLL bool IsPalindrome(int x);								//������
HEAD_DLL int MinDepth(TreeNode* root);							//������
HEAD_DLL bool ContainsDuplicate(vector<int>& nums);				//������
HEAD_DLL int MaxDepth(TreeNode* root);							//������
HEAD_DLL int HammingWeight(unsigned int n);						//�ڰ���
HEAD_DLL string AddBinary(string a, string b);					//�ھ���
HEAD_DLL vector<string> BinaryTreePaths(TreeNode* root);		//��ʮ��
HEAD_DLL bool NimGame(int n);									//��ʮһ��
HEAD_DLL bool IsValid(string str);								//��ʮ����
HEAD_DLL int myAtoi(string str);								//��ʮ����
HEAD_DLL int SingleNumber(vector<int>& nums);					//��ʮ����
HEAD_DLL bool WordPattern(string Pattern, string str);			//��ʮ����
HEAD_DLL unsigned int ReverseBits(unsigned int n);				//��ʮ����
HEAD_DLL bool WordBreak(string str, vector<string>& wordDict);  //��ʮ����
HEAD_DLL vector<int> PlusOne(vector<int>& digits);              //��ʮ����
HEAD_DLL int Sqrt(int y);                                       //��ʮ����
HEAD_DLL void MoveZeroes(vector<int>& nums);                    //�ڶ�ʮ��
HEAD_DLL int Reverse(int x);                                    //�ڶ�ʮһ��
HEAD_DLL void Rotate(vector<int>& nums, int k);                 //�ڶ�ʮ����
HEAD_DLL vector<string> RestoreIpAddresses(string s);           //�ڶ�ʮ����
HEAD_DLL int LengthOfLongestSubstring(char * s);                //�ڶ�ʮ����
HEAD_DLL ListNode* Partition(ListNode* head, int x);            //�ڶ�ʮ����
#endif

