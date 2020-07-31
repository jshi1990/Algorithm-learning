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

/*杨辉三角 II
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?*/

class Solution:
	def getRow(self, rowIndex: int)->List[int] :
	Row_List = []
	Row_Pre = []
	if (rowIndex == 1) :
		Row_List.append(1)
		if (rowIndex == 2) :
			Row_List.append(1)
			Row_List.append(1)

			Row_Pre = self.getRow(rowIndex - 1)     #get list from previous function
			for x in range(0, rowIndex) :
				if x == 0 or x == rowIndex - 1 :
					a = 1
					a = Row_Pre[x] + Row_Pre[x - 1]
					Row_List.append(a)
					return Row_List


/*
 斐波那契数
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.
Given N, calculate F(N).



Example 1:

Input: 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Example 2:

Input: 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
Example 3:

Input: 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.


这里面我们用了一个表去存已经递归过的元素，
因为在递归过程中会产生很多的已经递归过的变量重复出现，所以我们利用这个表存储中间的变量
计算机在处理过程中发现如何这个变量在之前已经分析过则直接返回元素。
*/

int Temp[31] = { 0 }; 
int fib(int N) {
	if (N == 0)
	{
		Temp[0] = 0;
		return 0;
	}
	if (N == 1)
	{
		Temp[1] = 1;
		return 1;
	}
	if (Temp[N] != 0) return Temp[N];     //在这里面我们直接返回了已经分析过的元素。

	Temp[N] = fib(N - 1) + fib(N - 2);

	return Temp[N];

}
/*
爬楼梯
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

这个题目的思想和之前的是一样的我们发现爬楼梯 N的次数相当于前面 N-1和N-2 次数的和

首先我们找到限制边界 楼层是1 和 2 然后我们用表去记录每次的数据
这道题和费波那奇数列一个道理 请记住这个模板
*/


int temp[46] = { 0 };
int climbStairs(int n) {
	if (n == 1)
	{
		temp[n] = 1;
		return 1;
	}
	if (n == 2) {
		temp[n] = 2;
		return 2;
	}
	if (temp[n] != 0) return temp[n];
	temp[n] = climbStairs(n - 1) + climbStairs(n - 2);

	return temp[n];
}