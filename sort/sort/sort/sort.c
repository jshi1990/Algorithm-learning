/*
排序 
在这里我们重点研究的是
1. 冒泡排序法
2. 插入排序法
3. merge排序法
4. 希尔排序法
5. 选择排序法


*/
/*选择排序法：
1. 一种最简单的排序算法是这样的首先，找到数组中最小的那个元素，其次，将他和数组的第一个元素交换位置

再次将它和数组的第一个元素交换位置，字词在剩下的元素中找到最小的元素，将它与数组的第二个元素交换位置

核心思想就是从剩下的数组中找到最小的元素和整个数组剩下的元素的第一个元素进行交换。

*/

#include <stdio.h>

#define MAX(a,b)  ( (a) > (b) ? (a) : (b))
#define MIN(a,b)  ( (a) < (b) ? (a) : (b))


void swap(unsigned int *a, unsigned int *b)
{

	unsigned int temp ;
	
	temp = *a;

	*a = *b;

	*b = temp;

}


/*
这个函数是一个由小到大的排序

*/
void Select_Sort(unsigned int* a, unsigned int Array_Len)
{
	
	for (unsigned int i = 0; i < Array_Len; i++)
	{
		unsigned int min = a[i];                                  //每次确定最小的值存放的位置。
		for (unsigned int j = i+1; j < Array_Len; j++) {
			if (min > a[j])
			{
				min = a[j];
				swap(&a[i], &a[j]);


			}
			
		}
		
    
		


	}


	

}

#define LONG

void main(void)
{
#ifdef LONG
	unsigned int a[] = { 232,43,5,4312,521,43,324324,564,32,3243,3,4,543,64,2,67234,7,45,67,653,354,54223,4,5,43,561,5,64,213,535,43,43,43,531,4 };
#else
	unsigned int a[] = {3,2,1};
#endif // LONG

	

	Select_Sort(a, sizeof(a) / sizeof(unsigned int));

	for (unsigned int i = 0; i < sizeof(a) / sizeof(unsigned int); i++)
	{
		printf("%u, ", a[i]);

	}

	while (1);

}