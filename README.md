# 我的算法学习之路

自己写的或搜集的算法

| 目录 | 描述 |
| :--: | :--: |
| fibonacci | 斐波那契数列实现算法 |
| sort | 排序算法 |
| search | 查找算法 |



## fibonacci

斐波那契数列算法，包含6种思路，5中算法：

* 算法1：递归，时间复杂度 **O(2^n)**
* 算法2：线性递归，也叫记忆法，记录上一次的计算结果，时间复杂度 **O(n) **
* 算法3：动态规划，自小而大进行计算，时间复杂度 **O(n) **
* 算法4：静态存储法，通过计算将fibonacci数列存入数组中，以备查询
* 算法5：通项公式算法。计算机不能真正表示无理数，此算法在没有实现意义 
* 算法6：矩阵求解，时间复杂度 **O(logn)** 



## sort

排序算法，包含：

* 起泡排序`BubbleSort1`，时间复杂度 **O(n^2)**
* 改进后的起泡排序`BubbleSort2`，时间复杂度 **O(n^2)**
* 归并排序`MergeSort`，时间复杂度 **O(nlogn)**
* 选择排序`SelectSort`，时间复杂度 **O(n^2)**
* 插入排序`InsertSort`，时间复杂度 **O(n^2)**



## search

查找算法，包含：

* 二分查找`BinSearch`，时间复杂度 **O(logn)**
* Fibonacci查找`FibSearch`，时间复杂度 **O(logn)**