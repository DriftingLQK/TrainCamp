#include<iostream>
#include<algorithm>
#include"Solve_Question_Code.h"
using namespace std;
/*************��7�⣺*********************************************
[Ҫ��]
����һ�����������ҳ��������ȡ�
�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
*************************************************************************/

//�ҵ�������
int MaxDepth(TreeNode* root)
{
	if (root == NULL) return 0;
	int maxdepth = max(MaxDepth(root->left), MaxDepth(root->right)) + 1;
	return maxdepth;

}

