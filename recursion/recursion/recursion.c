/*recursion:
In computer science, recursion is a method of solving a problem where the solution depends on solutions to smaller instances of the same problem.[1]
Such problems can generally be solved by iteration, but this needs to identify and index the smaller instances at programming time. 
Recursion solves such recursive problems by using functions that call themselves from within their own code. 
The approach can be applied to many types of problems, and recursion is one of the central ideas of computer science.[2]

*/


/*
我们开始学习递归的内容
这里我们使用的是LeetCode的原题来巩固递归的思想。
在理论上递归可以代替所有的循环。
递归会消耗栈 所以说一般c语言中会利用循环来代替递归
不过在很多的应用中，递归的代码比较简洁和清晰，比如快速排序和归并排序算法

其实递归的原理在于 给定一个边界的条件 然后把大问题变成小问题依次的解决然后连接到一起。
通过下面的练习我们来巩固递归的问题

*/

/*
Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.



Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]


*/
void swap(char *a, char* b)
{
	char temp;
	
	temp = *a;

	*a = *b;

	*b = temp;


}
/*
请利用递归去做这道题目
递归的做法：
1. 给出边界条件：
   如以下的程序我们的边界的条件是
	if (head >= tail)
		return;
   即当头部比尾部的指针地址大或者等于的时候我们就停止排序

2. 完成一小块的任务
   我们用swap去完成字母的swap

3. 然后利用递归的形式自己调用自己 从而每一次递归的时候都会完成一次的swap

我们来看 递归的思想其实就是分治的思想，就是把一个大型的任务分治成小的任务，然后每次都是按照一个规律就进行。
我们只要设定好边界的条件就能写出此类的程序
*/
void reverseString(char* s, int sSize) {
	char* head = s;
	char* tail = s + sSize - 1;
	if (head >= tail)
		return;
	swap(head, tail);
	reverseString(head + 1, sSize - 2);


}

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

