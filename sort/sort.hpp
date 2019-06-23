/**
 * desc: 排序算法 
 * file: sort.hpp
 *
 * author:  myw31415926
 * date:    20190604
 * version: V0.1
 *
 * the closer you look, the less you see
 */

#ifndef _SORT_V01_H
#define _SORT_V01_H

#include <iostream>
#include "search.hpp"

namespace sort {

typedef int Rank;   // 向量的秩

template<typename T>
inline static void Swap(T& t1, T& t2)
{
    T t = t1;
    t1 = t2;
    t2 = t;
}

/**
 * 起泡排序算法
 */
template<typename T>
bool Bubble1(T* elem, Rank lo, Rank hi)
{
    bool sorted = true;                     // 整体有序标志
    while (++lo < hi) {                     // 自左向右，逐一检查个相邻元素
        if (elem[lo - 1] > elem[lo]) {      // 逆序对，需要交换
            sorted = false;                 // 表示整体尚未有序
            Swap(elem[lo - 1], elem[lo]);   // 需要交换
        }
    }
    return sorted;
}

template<typename T>
void BubbleSort1(T* elem, Rank lo, Rank hi)
{
    // 逐趟做扫描，每次扫描都会讲最大元素移至末尾
    while (!Bubble1(elem, lo, hi--));
}

/**
 * 起泡排序算法改进
 * 改进思路：记录最后一个（最右侧）逆序对的位置，下一趟扫描只需要比较到最后一个
 *           逆序对的地方；后面都是有序的，不需要比较
 */
template<typename T>
Rank Bubble2(T* elem, Rank lo, Rank hi)
{
    Rank last = lo;                         // 最后一个逆序对初始化为左边界lo
    while (++lo < hi) {                     // 自左向右，逐一检查个相邻元素
        if (elem[lo - 1] > elem[lo]) {      // 逆序对，需要交换
            last = lo;                      // 更新最后一个逆序对的位置
            Swap(elem[lo - 1], elem[lo]);   // 需要交换
        }
    }
    return last;
}

template<typename T>
void BubbleSort2(T* elem, Rank lo, Rank hi)
{
    // 逐趟做扫描，直至整体有序
    while (lo < (hi = Bubble2(elem, lo, hi)));
}

///////////////////////////////////////////////////////////////////////////////
/**
 * 归并排序算法
 */
template<typename T>
void Merge(T* elem, Rank lo, Rank mid, Rank hi)
{
    // 二路归并原理：将两个有序序列合并为一个有序序列
    T* all = elem + lo;         // 合并后的向量all[0, hi - lo) = elem[lo, hi)

    int llen = mid - lo;        // 左半部分的长度
    T* left = new T[llen];      // 左边子向量left[0, llen) = elem[lo, mid)
    for (Rank i = 0; i < llen; i++) {
        left[i] = all[i];       // 复制前半部分到B中
    }

    int rlen = hi - mid;        // 右半部分的长度
    T* right = elem + mid;      // 右边子向量right[0, rlen) = elem[mid, hi)

    // 比较left和right中的较小者，赋值到all的末尾
    Rank i = 0, j = 0, k = 0;
    while ((j < llen) && (k < rlen)) {
        if (left[j] <= right[k]) {
            all[i++] = left[j++];
        } else {
            all[i++] = right[k++];
        }
    }

    while (j < llen) {          // 若存在，处理左侧的剩余
        all[i++] = left[j++];
    }
    while (k < rlen) {          // 若存在，处理右侧的剩余
        all[i++] = right[k++];
    }

    delete[] left;
}

template<typename T>
void MergeSort(T* elem, Rank lo, Rank hi)
{
    if (hi - lo < 2) {          // 单元素区间必然有序
        return;
    }
    int mid = (lo + hi) >> 1;   // 以中点为界
    MergeSort(elem, lo, mid);   // 对前半段排序
    MergeSort(elem, mid, hi);   // 对后半段排序
    Merge(elem, lo, mid, hi);   // 归并
}

///////////////////////////////////////////////////////////////////////////////
/**
 * 选择排序算法
 * 每次循环找到最大元素，放置到末尾
 */
template<typename T>
static Rank SelectMax(T* elem, Rank lo, Rank hi)
{
    Rank max = lo;
    for (Rank cur = lo; cur < hi; cur++) {
        if (elem[cur] >= elem[max]) {   // 必须是>=，选最靠后的最大值，保证稳定性
            max = cur;
        }
    }
    return max;
}

template<typename T>
void SelectSort(T* elem, Rank lo, Rank hi)
{
    Rank max;
    while (hi - lo > 1) {
        max = SelectMax(elem, lo, hi);
        // std::cout << "max = " << max << std::endl;
        Swap(elem[max], elem[--hi]);    // 交换最大元素和末尾元素
    }
}

///////////////////////////////////////////////////////////////////////////////
/**
 * 插入排序算法
 * 将元素插入到有序的前缀部分
 */
template<typename T>
void InsertSort(T* elem, Rank lo, Rank hi)
{
    for (Rank i = lo + 1; i < hi; i++) {    // 从第2个元素开始，单个元素肯定有序
        T e = elem[i];

        // 用二分法查找元素i，返回不大于e的最后一个元素的下标，r表示e要插入的位置
        Rank r = search::BinSearchUp(e, elem, lo, i) + 1;
        // std::cout << "BinSearchUp elem = " << e << ", rank = " << r << std::endl; 

        // 将r插入到有序部分elem[lo, i)中，会有元素后移
        for (Rank j = i; j > r; j--) {  // 从后向前覆盖元素
            elem[j] = elem[j - 1];
        }
        elem[r] = e;
    }
}

}   // sort

#endif // _SORT_V01_H
