#include<iostream>
#include <vector>
#include<string>
#include"Solve_Question_Code.h"
using namespace std;
/**********************��10�⣺*************************
[Ҫ��]
����һ�����������������дӸ��ڵ㵽Ҷ�ӽڵ��·����
*********************************************************/
vector<string> BinaryTreePaths(TreeNode* root)
{
	vector<string> Paths;
	if (root == NULL)               //�����Ϊ�գ����ؿ�����
		return Paths;
	if (root->left == NULL && root->right == NULL)  //�������������������Ϊ�գ��򷵻ظ�
	{
		Paths.push_back(to_string(root->val));     //to_string  ������ת��Ϊ�ַ���string��
	}
	vector<string> left = BinaryTreePaths(root->left);   //����������·��
	for (unsigned int i = 0; i < left.size(); ++i)
	{
		Paths.push_back(to_string(root->val) + "->" + left[i]);
	}
	vector<string> right = BinaryTreePaths(root->right);  //����������·��
	for (unsigned int i = 0; i < right.size(); ++i)
	{
		Paths.push_back(to_string(root->val) + "->" + right[i]);
	}
	return Paths;
}
