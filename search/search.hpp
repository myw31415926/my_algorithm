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

}   // search

#endif // _SEARCH_V01_H
