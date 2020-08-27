#include<iostream>
#include <vector>
#include<string>
#include"Solve_Question_Code.h"
using namespace std;
/**********************第10题：*************************
[要求]
给定一个二叉树，返回所有从根节点到叶子节点的路径。
*********************************************************/
vector<string> BinaryTreePaths(TreeNode* root)
{
	vector<string> Paths;
	if (root == NULL)               //如果树为空，返回空容器
		return Paths;
	if (root->left == NULL && root->right == NULL)  //如果左子树和右子树都为空，则返回根
	{
		Paths.push_back(to_string(root->val));     //to_string  将整型转化为字符串string型
	}
	vector<string> left = BinaryTreePaths(root->left);   //计算左子树路径
	for (unsigned int i = 0; i < left.size(); ++i)
	{
		Paths.push_back(to_string(root->val) + "->" + left[i]);
	}
	vector<string> right = BinaryTreePaths(root->right);  //计算右子树路径
	for (unsigned int i = 0; i < right.size(); ++i)
	{
		Paths.push_back(to_string(root->val) + "->" + right[i]);
	}
	return Paths;
}
