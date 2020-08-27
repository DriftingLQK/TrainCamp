#include<iostream>
#include"Solve_Question_Code.h"
using namespace std;

ListNode* Partition(ListNode* head, int x)
{
	if (head == NULL || head->next == NULL)       //如果为空 ，就返回空
		return head;

	ListNode* Now = head;
	ListNode* pre_min, *Now_min, *pre_max, *Now_max;
	Now_min = new ListNode;   //创建存小数的链表
	Now_max = new ListNode;   //创建存大数的链表
	pre_min = Now_min;        //小数链表的指针
	pre_max = Now_max;		  //大数链表的指针
	while (Now != NULL)
	{
		if (Now->val < x)   //与给定的值进行判断
		{
			Now_min->next = Now;      //如果小于给定的值，则将其存到较小的部分
			Now_min = Now_min->next;
		}
		else
		{
			Now_max->next = Now;   // 如果大于给定的值，则将其存到较大的部分
			Now_max = Now_max->next;
		}
		Now = Now->next;   //继续遍历链表
	}
	Now_min->next = pre_max->next;    //将链表连接起来
	Now_max->next = NULL;
	ListNode* Result = pre_min->next;  //指向链表第一个值
	delete pre_max;   //释放内存
	delete pre_min;   //释放内存
	return Result;
}
