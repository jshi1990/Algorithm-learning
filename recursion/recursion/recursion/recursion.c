#include<stdio.h>

/*
�������������еĽڵ�
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.



Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.

����˼�룬�뿴��������ǵ�ԭ����һ����
1.����ȷ���޶�������
  ������head = NULL return NULL
  head != NULL and head->next == NULL 
  return head
2.�������ǿ�ʼ��С������д��� 
���Ȱ�1 �� 2 ��ָ�����
Ȼ��1��ָ����ָ���˺����3->4�������
��ô���ǾͿ����õݹ�ķ�ʽ�ݹ�3->4�������Ȼ���ٰѷ��ص�ֵ����ǰ���1->next.

���ٴ�ע��ݹ��˼����
1. �����޶�������
2. ����������е�һ��С����
3. �����ݹ�ķ��̡�

*/

/*1->2->3->4   => 2->1->4->3*/
struct ListNode* swapPairs(struct ListNode* head){
	struct ListNode *p = NULL;
	struct ListNode *q = NULL;
	if ((head == NULL))
		return NULL;
	if ((head != NULL) && (head->next == NULL))
		return head;
	p = head->next;
	q = p->next;
	p->next = head;
	head->next = swapPairs(q);

	return p;
}
