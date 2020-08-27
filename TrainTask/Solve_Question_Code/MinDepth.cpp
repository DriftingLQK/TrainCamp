#include<iostream>
#include <algorithm>
#include"Solve_Question_Code.h"
using namespace std;
/*******************************第五题：************************
[要求]
给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
***************************************************************/
   //找到最小深度
int MinDepth(TreeNode* root)
{
	if (root == NULL) return 0;
	if (root->left == NULL)
		return MinDepth(root->right) + 1;
	if (root->right == NULL)
		return MinDepth(root->left) + 1;
	int mindepth = min(MinDepth(root->left), MinDepth(root->right)) + 1;
	return mindepth;

}

