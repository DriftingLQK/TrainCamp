#include<iostream>
#include <algorithm>
#include"Solve_Question_Code.h"
using namespace std;
/*******************************�����⣺************************
[Ҫ��]
����һ�����������ҳ�����С��ȡ�
��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������
***************************************************************/
   //�ҵ���С���
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

