/**
 * desc: 基础方法
 * file: utils.hpp
 *
 * author:  myw31415926
 * date:    20190610
 * version: V0.1
 *
 * the closer you look, the less you see
 */

#ifndef _UTILS_HPP
#define _UTILS_HPP

#include <ctime>
#include <cstdlib>

namespace utils {

/**
 * 产生n个[0, max)的随机数，保存在buf中
 * #define RAND_MAX 2147483647(INT_MAX)
 */
void Random(int* buf, int n, int max = RAND_MAX)
{
    srand((unsigned int)time(0));
    for (int i = 0; i < n; i++) {
        buf[i] = rand() % max;
    }
}

}   // utils

#endif // _UTILS_HPP
