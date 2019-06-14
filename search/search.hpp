/**
 * desc: 向量搜索算法
 * file: search.hpp
 *
 * author:  myw31415926
 * date:    20190611
 * version: V0.1
 *
 * the closer you look, the less you see
 */

#ifndef _SEARCH_V01_H
#define _SEARCH_V01_H

#include <iostream>
#include "fib.hpp"

namespace search {

typedef int Rank;   // 向量的秩

/**
 * 二分查找：在有序向量区间[lo, hi)查找元素e
 * 成功返回元素下标，失败返回-1
 */
template<typename T>
Rank BinSearch(const T& e, T* elem, Rank lo, Rank hi)
{
    while (lo < hi) {               // 有3个分支，每次迭代都可能要做两次比较
        Rank mid = (lo + hi) >> 1;  // 以中心为轴点
        if (e < elem[mid]) {
            hi = mid;               // 深入左侧 [lo, mid)
        } else if (elem[mid] < e) {
            lo = mid + 1;           // 深入右侧 (mid, hi)
        } else {
            return mid;             // 刚好命中
        }
    }

    return -1;                      // 查找失败
}

/**
 * Fibonacci查找：在有序向量区间[lo, hi)查找元素e
 * 成功返回元素下标，失败返回-1
 */
template<typename T>
Rank FibSearch(const T& e, T* elem, Rank lo, Rank hi)
{
    utils::Fib fib(hi - lo);        // 用数组长度创建Fibonacci数列，最大项刚好超过数组长度

    while (lo < hi) {
        while (hi - lo < fib.Get()) {
            fib.Prev();             // 前向迭代，查找到不超过数组长度的最大项，确定切分点
        }

        Rank mid = lo + fib.Get() - 1;  // 按黄金比例切分，注意减1
        if (e < elem[mid]) {
            hi = mid;                   // 深入左侧 [lo, mid)
        } else if (elem[mid] < e) {
            lo = mid + 1;               // 深入右侧 (mid, hi)
        } else {
            return mid;                 // 刚好命中
        }
    }

    return -1;                          // 查找失败
}

/**
 * 二分查找：在有序向量区间[lo, hi)查找元素e，改为2个分支
 * 成功返回元素下标，失败返回-1
 */
template<typename T>
Rank BinSearchV2(const T& e, T* elem, Rank lo, Rank hi)
{
    while (1 < hi - lo) {           // 有2个分支，每次迭代都只做1次比较，宽度为1时停止
        Rank mid = (lo + hi) >> 1;  // 以中心为轴点
        (e < elem[mid]) ? hi = mid : lo = mid;
    }

    // 退出时，hi = lo + 1，即查找区间只有1个元素: elem[lo]
    // 比较目标元素和elem[lo]，返回下标或-1
    return (e == elem[lo]) ? lo : -1;
}

/**
 * 二分查找：在有序向量区间[lo, hi)查找元素e
 * 返回不大于e的最后一个元素的下标
 */
template<typename T>
Rank BinSearchUp(const T& e, T* elem, Rank lo, Rank hi)
{
    while (lo < hi) {               // 不变性：A[0, lo) <= e < A[hi, n)
        Rank mid = (lo + hi) >> 1;  // 以中心为轴点
        (e < elem[mid]) ? hi = mid : lo = mid + 1;  // [lo, mid) 和 (mid, hi)
    }

    // 退出时，elem[lo = hi]为大于e的最小元素
    // lo - 1即不大于e的元素的最大秩
    return lo - 1;
}

}   // search

#endif // _SEARCH_V01_H
