﻿# Algorithm-learning
re-learn algorithm...

现在得开始好好学习了，首先先从算法开始。
我将会努力坚持每天上传一个算法程序，做到有始有终。参考资源是leetcode和算法4的图书，我将会边学边把程序传上来。
README将会随着我的程序更新而更新。
我们采取的是一步一步的改进程序的方式来学习算法

1.冒泡算法
我们在程序中写入了三种冒泡排序的方法
第一种是最简单的 依次改进加入了很多来使得冒泡排序更快

2. 选择排序法
一种最简单的排序算法是这样的首先，找到数组中最小的那个元素，其次，将他和数组的第一个元素交换位置

再次将它和数组的第一个元素交换位置，字词在剩下的元素中找到最小的元素，将它与数组的第二个元素交换位置

核心思想就是从剩下的数组中找到最小的元素和整个数组剩下的元素的第一个元素进行交换。

3.直接插入排序
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

3.希尔排序
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