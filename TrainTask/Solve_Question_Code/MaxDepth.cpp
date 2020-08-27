#include<iostream>
#include<algorithm>
#include"Solve_Question_Code.h"
using namespace std;
/*************第7题：*********************************************
[要求]
给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
*************************************************************************/

//找到最大深度
int MaxDepth(TreeNode* root)
{
	if (root == NULL) return 0;
	int maxdepth = max(MaxDepth(root->left), MaxDepth(root->right)) + 1;
	return maxdepth;

}

