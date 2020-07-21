/*
排序 
在这里我们重点研究的是
1. 冒泡排序法
2. 插入排序法
3. merge排序法
4. 希尔排序法
5. 选择排序法


*/

#include <stdio.h>
#include <stdbool.h>

typedef unsigned int uint32;
typedef unsigned char uint8;



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


/*选择排序法：
1. 一种最简单的排序算法是这样的首先，找到数组中最小的那个元素，其次，将他和数组的第一个元素交换位置

再次将它和数组的第一个元素交换位置，字词在剩下的元素中找到最小的元素，将它与数组的第二个元素交换位置

核心思想就是从剩下的数组中找到最小的元素和整个数组剩下的元素的第一个元素进行交换。

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



/*
冒泡排序法
这里我们先使用的是最简单的冒泡排序法

他会检查 相邻两个元素的大小然后进行交换

但是这种效率太低。不是经典的冒泡算法 下面来说明一下真正的冒泡算法

*/
void Bubble_Sort1(uint32* buff, uint32 len)
{
	for (uint32 i = 0; i < len; i++)
	{
		for (uint32 j = i + 1; j < len; j++)
		{
			if (buff[i] > buff[j])
			{
				swap(&buff[i], &buff[j]);         


			}

		}

	}


}

/*
冒泡法更改1.
举例 我们的数据是4，3,2,1我们需要从小到大的排列
首先
第一次 4,3,1，2
第二次4,1,3,2
第三次1,4,3,2

第四次1,4,2,3
第五次1,2,4,3
第六次1,2,3,4

我们可以发现这个冒泡法是选取了最后一个元素作为冒泡的元素 然后开始和前面的元素进行比较
当这个元素走到了应该到的地方的时候则选取倒数第二个元素(此时这个元素变成了最后的一个元素)进行冒泡的排列 以此类推

*/

void Bubble_Sort2(uint32* buff, uint32 len)
{
	for (uint32 i = 0; i < len; i++)
	{ 
		for (uint32 j = len - 1; j > i; j--)   //从倒数第一个元素开始进行冒泡的选取和排列
		{
			if (buff[j] < buff[j - 1])
				swap(&buff[j], &buff[j - 1]);     //如果是前面的元素大于后面的元素则进行交换


		}


	}

}


/*
冒泡法更改2
我们在上面发现 如果当数组中很多的数都一样的话 或者已经是后面的大于前面的 则不用在进行判断了。我们这样子可以节省很多的次数
举例 比如说数组里面 1,2,4,3 我们只需要判断一次就可以了


*/
void Bubble_Sort3(uint32* buff, uint32 len)
{
	bool flag = 1;
	for (uint32 i = 0; i < len && flag; i++)
	{
		for (uint32 j = len - 1; j > i; j--)   //从倒数第一个元素开始进行冒泡的选取和排列
		{
			flag = 0;
			if (buff[j] < buff[j - 1]) {
				swap(&buff[j], &buff[j - 1]);     //如果是前面的元素大于后面的元素则进行交换
				flag = 1;
			}
		}


	}

}
/*
直接插入排序
举例8 16 1 4 5 2
一开始用第一个元素作为锚定点，查看后面的元素，由于16比8 大 所以不动
往后找，发现1比8小所以插入到8的前面。然后让整个排序好的序列往右边移动

1 8 16 4 5 2

1 4 8 16 5 2

1 4 5 8 16 2

1 2 4 5 8 16 


我们也可以这么看待这个问题 我们只是比较相邻两个数的大小 我们假设第一个元素是有序的 我们让第一个元素和第二个元素比较，

然后排序 之后第二个元素和第三个元素比较 以此类推


*/
void Insert(uint32* buff, uint32 len)
{
	uint32 temp;
	for (uint32 i = 1; i < len; i++)
	{
		if (buff[i] < buff[i - 1])    //这里我们只是比较有序数列的最后一个数字（最大的数字）和后面的序列
		{
		   temp = buff[i];
		   for(uint32 j = 0; temp < buff[i-1]; j++)
                  

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

	

	Bubble_Sort3(a, sizeof(a) / sizeof(unsigned int));

	for (unsigned int i = 0; i < sizeof(a) / sizeof(unsigned int); i++)
	{
		printf("%u, ", a[i]);

	}

	while (1);

}