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

	unsigned int temp;

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
		for (unsigned int j = i + 1; j < Array_Len; j++) {
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
	uint8 flag = 1;
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
这道题的思想：
首先 8 16 1 4 5 2
当我们发现了1 的时候 我们的移动是这个样子的：
首先将1 存入一个temp变量里面
然后移动前面的有效数组
8， 16， 16，4，5，2
8，8，16，4，5，2
然后我们把1放在第一个元素那里
1，8，16，4，5，2
我们需要注意的是边界的问题。
*/
void Insert(uint32* buff, uint32 len)
{
	uint32 temp;
	int j;
	for (uint32 i = 1; i < len; i++)
	{
		if (buff[i] < buff[i - 1])    //这里我们只是比较有序数列的最后一个数字（最大的数字）和后面的序列
		{
			temp = buff[i];                  //把这个数存入一个temp 里面 之后前面的数会把这个数字原来的地方覆盖掉
			for (j = i - 1; (temp < buff[j]) && (j >= 0); j--)  //在有序的数列中找到比这个数大的第一个数 然后把这个位置给到这个数 
			{                                                   //如果那个数是一个最小的数字的话 应该把这个数字放到最一开始的位置，所以说我们需要j>=0
				buff[j + 1] = buff[j];            //把在i之前的数字 往后面一一位。
			}
			buff[j + 1] = temp;                        //把temp中的元素放到空出的那个位置上面。 当我们找到了 那个不要大于有序数组里面的数字 我们需要+1排在这个数字的前面。


		}


	}




}
/*
下面是希尔排序
原理
我们首先假设现在有的数组是 8 16 1 4 5 2
我们首先先把这个数组分成【8，1，5】 【16，4，2】
然后我们对于这里的每个数组进行插入排序
我们就会得到以下的数组
【1，5，8】 【2，4，16】
那么总的数组就会变成
1 2 5 4 8 16
然后再进行一次的插入排序即可
编程的原理是：
1. 我们首先把数组分成 小的有间隔的数组 比如上面的数组 我们是每隔一个数字 选取一个数 作为一个数组
2. 我们分别对分开的数组进行插入排序
3. 举例如果我们一开始分成了4组 那么第二次排序的时候四组就会变成2组 以此类推 我们最后当组为一组的时候我们就可以最后一次的进行大的插入排序
4. 请注意插入排序的算法在对有一定顺序的数组进行排序的时候速度十分的快。
*/
void Shell_Sort(uint32* buff, uint32 len)
{
	uint32 gap = len;
	uint32 temp;
	int j = 0;
	do {
		gap = gap / 5;                                            //这里面我们把相互隔开的数组定位1 那么我们的第一个选取元素的数组的index就是0 2 4  第二个数组的选取的元素就是1 3 5
		for (int i = gap; i < len; i++)                          //这里我们开始分别对两个数组进行插入的排序
		{
			if (buff[i - gap] > buff[i])                        //这个排序我们都是从小到大的排序那么当后面的数字小于前面的数字的话应该做判断。
			{
				temp = buff[i];                                //把这个后面的需要调整的数字先保存下来
				for (j = i - gap; j >= 0 && buff[j] > temp; j = j - gap)
				{
					buff[j + gap] = buff[j];                          //这里面会再次进行插入排序

				}
				buff[j + gap] = temp;                                //我们这里调用的是直接插入排序

			}
		}

	} while (gap >= 1);



}

/*
归并排序：
原理 我们假设我们的数组是 8 16 1 4 5 2
那我们首先从中间劈开数组 这个数组就变成了 【8 16 1】和 【4 5 2】
然后我们在分解这个这个数组 就变成了 【8，16】 【1】   【4，5】【2】
此时我们对每个数组进行排列，这里面我们建立一个新的数组  这个数组会优先的选取比较小的数字存入
比如说 【8 16】 【1】这部分存入数组就是
【1 8 16】
【4,5】 [2] 这部分在数组里面就是
【2,4,5】
然后最后在把这两个已经排序的数组再次放入这个新建立的数组里面去进行最后一次的排序
得出的结果就是最终的结果
我们这里首先利用递归的算法去解决。
实际上这个算法就是把整个的数组劈成两两数字比较 然后再归并成两组数组比较，然后再次归并成更大的数列 以此类推。
编程思想：
1. 我们首先先把数组从中间劈开
2. 然后利用递归的思路把这些数组全部分成两两比较的最小数组
3. 当比较完之后我们利用递归的方式把数组在还原回来
请注意我们这里其实是利用了动态规划的特点去写这个归并的程序。
不过这个归并的程序需要外部的数组来帮助排序 比较浪费内存 不想希尔排序 内存的复杂度只是1
*/

void merge(uint32* left_buff, uint32 left_len, uint32* right_buff, uint32 right_len)
{
	uint32 temp[100] = { 0 };                  //建立一个临时的数组表用于储存排序的数据
	uint32 i = 0, j = 0, k = 0;
	while ((j < left_len) && (k < right_len))     //这里面是把小的数存到临时数组的前面。
	{
		if (left_buff[j] <= right_buff[k])              //请注意这个函数是归并算法里面真正的排序部分 Merge Sort只是把函数分成了小份儿
		{
			temp[i++] = left_buff[j++];

		}
		if (left_buff[j] > right_buff[k])
		{
			temp[i++] = right_buff[k++];
		}

	}
	while (j < left_len)                              //把最后剩下的数据写入temp里面
		temp[i++] = left_buff[j++];
	while (k < right_len)
		temp[i++] = right_buff[k++];
	for (int m = 0; m < left_len + right_len; m++)      // 我们把新排列的数据全部放到左边的数组 用于和新的右边的数组进行新的排序
		left_buff[m] = temp[m];

}

void Merge_sort(uint32* buff, uint32 len)
{
	if (len > 1)  //我们假设我们的排序都是大于1 的数组
	{
		uint32 left = len / 2;                              //左边数组的长度
		uint32 right = len - left;                          //right 数组的长度
		uint32* left_pointer = buff;                       //需要归并的时候左边的数组的指针
		uint32* right_pointer = (buff + left);              //需要归并时候右边的数组的指针

		Merge_sort(left_pointer, left);                       //把左边的数组再次的分成小段
		Merge_sort(right_pointer, right);                     //把右边的数组分成小段
		merge(left_pointer, left, right_pointer, right);     //把所有的数组进行归并。


	}


}


/*
Quick Sort
Quick Sort 的原理
举例我们有一个数列 19 97 09 17 1 8

那么我们可以选择在最左边的那个数字为锚定点，
如果然后设置两个指针一个指向数组的开头（开头指针） 另外一个指向数组的末尾（末尾指针）
我们首先先看末尾的数字 如果末尾指针的数字小于锚定点 则末尾指针的数字和开头指针的数字互换 （只做一次）
然后我们移动开头指针，再看开头指针的数字如果开头指针的数字大于末尾指针的数字 那么就把开头只指针的数字和末尾指针的数字交换，然后移动末尾指针（只是做一次） 然后重复之前的过程。


我们选择19 是锚定点
比如我们的数字的变化就是

我们会发现19 比 8 大 所以开头指针的数字和末尾指针的数据互换

8 97 09 17 1 19

之后开头指针加一位，那么就是97 和19 比较 因为97 大于19  所以说需要变换 那么数组就变成了

8 19 09 17 1 97

然后右边的指针指向了1 所以我们就变成了 8 1 09 17 19 97

然后我们再看做指针09 比17 小 所以不变
此时我们的数组变成了 8 1 09 17 19 97
那么 我们用锚定点把数组分成两组 一组是 8 1 09 19 另外是 97

我们再次把这两个数组进行排序。
最后我们就能得到一个顺序数列了。


*/
int Pivot(uint32* buff, int lo, int hi)              //返回指针最后重合的位置
{
	uint32 pivot = buff[lo];                        //我们这里选择最左边的那个数字为锚定点
	while (lo < hi)                                  //当两个指针重合的时候结束排序
	{
		while ((pivot <= buff[hi]) && lo < hi)         //当我们右边的数字大于锚定点的时候 末尾的指针++
			hi--;
		if (pivot > buff[hi] && lo < hi)                           //当锚定点的数值大于右边的数字的时候 则两个指针所指的数据进行交换
			swap(&buff[lo], &buff[hi]);
    //2. 第二部我们再来看锚定点和左边指针的关系。
		while ((pivot >= buff[lo]) && lo < hi)
			lo++;
		if (pivot < buff[lo] && lo < hi)
			swap(&buff[lo], &buff[hi]);




	}
	return lo;  //这里返回lo或者hi都是一样的结果 因为他们重合了
}


int Pivot2(uint32* buff, int lo, int hi)              //返回指针最后重合的位置
{
	
	int mid = lo + (hi - lo) / 2;

	if (buff[lo] > buff[hi])
		swap(&buff[lo], &buff[hi]);
	if (buff[mid] > buff[hi])
		swap(&buff[mid], &buff[hi]);
	if (buff[mid] > buff[lo])
		swap(&buff[mid], &buff[lo]);
	
	
	uint32 pivot = buff[lo];                        //我们这里选择最左边的那个数字为锚定点
	while (lo < hi)                                  //当两个指针重合的时候结束排序
	{
		while ((pivot <= buff[hi]) && lo < hi)         //当我们右边的数字大于锚定点的时候 末尾的指针++
			hi--;
		if (pivot > buff[hi] && lo < hi)                           //当锚定点的数值大于右边的数字的时候 则两个指针所指的数据进行交换
			swap(&buff[lo], &buff[hi]);
		//2. 第二部我们再来看锚定点和左边指针的关系。
		while ((pivot >= buff[lo]) && lo < hi)
			lo++;
		if (pivot < buff[lo] && lo < hi)
			swap(&buff[lo], &buff[hi]);




	}
	return lo;  //这里返回lo或者hi都是一样的结果 因为他们重合了
}


void Quick_Sort(uint32* buff, int lo, int hi)
{
	if (lo < hi)
	{
		int pivot = Pivot2(buff, lo, hi);
		Quick_Sort(buff, lo, pivot - 1);      //这个是左边的序列
		Quick_Sort(buff, pivot + 1, hi);      //这个是左边的序列
	}

}

void My_Quick_Sort(uint32* buff, uint32 len)
{
	Quick_Sort(buff, 0, len - 1);

}


#define LONG

void main(void)
{
#ifdef LONG
	unsigned int a[] = { 232, 43, 5, 4312, 521, 43, 564, 32, 3243, 3, 4, 543, 64, 2, 67234, 7, 45, 67, 653, 354, 54223, 4, 5, 43, 561, 5, 64, 213, 535, 43, 43, 43, 531, 4 };
#else
	unsigned int a[] = { 4,3,5,9,1 };
#endif // LONG


	//
	My_Quick_Sort(a, sizeof(a) / sizeof(unsigned int));

	for (unsigned int i = 0; i < sizeof(a) / sizeof(unsigned int); i++)
	{
		printf("%u, ", a[i]);

	}

	while (1);

}