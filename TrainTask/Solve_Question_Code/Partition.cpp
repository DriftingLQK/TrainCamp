#include<iostream>
#include"Solve_Question_Code.h"
using namespace std;

ListNode* Partition(ListNode* head, int x)
{
	if (head == NULL || head->next == NULL)       //���Ϊ�� ���ͷ��ؿ�
		return head;

	ListNode* Now = head;
	ListNode* pre_min, *Now_min, *pre_max, *Now_max;
	Now_min = new ListNode;   //������С��������
	Now_max = new ListNode;   //���������������
	pre_min = Now_min;        //С�������ָ��
	pre_max = Now_max;		  //���������ָ��
	while (Now != NULL)
	{
		if (Now->val < x)   //�������ֵ�����ж�
		{
			Now_min->next = Now;      //���С�ڸ�����ֵ������浽��С�Ĳ���
			Now_min = Now_min->next;
		}
		else
		{
			Now_max->next = Now;   // ������ڸ�����ֵ������浽�ϴ�Ĳ���
			Now_max = Now_max->next;
		}
		Now = Now->next;   //������������
	}
	Now_min->next = pre_max->next;    //��������������
	Now_max->next = NULL;
	ListNode* Result = pre_min->next;  //ָ�������һ��ֵ
	delete pre_max;   //�ͷ��ڴ�
	delete pre_min;   //�ͷ��ڴ�
	return Result;
}
