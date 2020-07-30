#include<stdio.h>

/*
两两交换链表中的节点
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.



Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.

解题思想，请看这道题我们的原理还是一样的
1.首先确定限定的条件
  在这里head = NULL return NULL
  head != NULL and head->next == NULL 
  return head
2.后面我们开始对小任务进行处理 
首先把1 和 2 的指针调换
然后1的指针又指向了后面的3->4这个任务
那么我们就可以用递归的方式递归3->4这个任务然后再把返回的值给到前面的1->next.

请再次注意递归的思想是
1. 给出限定的条件
2. 解决大问题中的一个小问题
3. 给出递归的方程。

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
