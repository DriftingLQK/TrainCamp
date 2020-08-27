#include "stdafx.h"
using namespace std;


/*   ���ݸ��������ݣ�����������*/

////TreeNode *CreateBTree2(TreeNode *root, int *num,  int *check,int& index)        //ǰ��ṹ
////{
////	int value = num[index];
////	if (value == 0)
////		return NULL;
////	else
////	{
////		root = new TreeNode;
////		root->val = num[index];
////		root->left = CreateBTree(root->left, num, ++index);
////		root->right = CreateBTree(root->right, num, ++index);
////	}
////	return root;
////}

TreeNode *CreateBTree(TreeNode *root, vector<int> &num, vector<int> &check, int n, int&index)//���������룬���Ϊ��ʱ������'0'
{
	if (num[index] == 0)   //�ж��Ƿ�Ϊ��
	{
		for (unsigned int i = 0; i < check.size(); i++)
		{
			if (index == check[i])
				return NULL;	
		}
	}
		

	root = new TreeNode;  //�½�һ�������
	root->val = num[index];         //������� root �� ��Ա���� val��left��right ����ֵ
	root->left = NULL;
	root->right = NULL;

	int Lnode = 2 * index + 1;
	int Rnode = 2 * index + 2;

	if (Lnode > n - 1)
		root->left = NULL;
	else
		root->left = CreateBTree(root, num, check, n, Lnode);

	if (Rnode > n - 1)
		root->right = NULL;
	else
		root->right = CreateBTree(root, num, check, n, Rnode);

	return root;
}
#pragma region    ��ӡ������
//void print(TreeNode *root, int h)
//{
//	if (root != NULL)
//	{
//		print(root->right, h + 1);
//		for (int i = 0; i<h; i++)
//			cout << "       ";
//		cout << root->val << endl << endl;
//		print(root->left, h + 1);
//	}
//	/*cout << endl;*/
//}
#pragma endregion