/**
 * desc: Fibonacci数列类，用于优化查找
 * file: fib.hpp
 *
 * author:  myw31415926
 * date:    20190613
 * version: V0.1
 *
 * the closer you look, the less you see
 */

#ifndef _FIB_HPP
#define _FIB_HPP

namespace utils {

/**
 * Fibonacci数列类
 * 动态规划生成一个不小于max的最小Fibonacci项
 * 均为int型，很快就会数值溢出，但只是为了确定下标，不会存在溢出和效率问题
 */
class Fib
{
public:
    // 初始化为不小于max的最小Fibonacci项
    Fib(int max) : f_(1), g_(0)     // fib(-1), fib(0)
    {
        while (g_ < max) Next();
    }

    // 获取当前Fibonacci项，O(1)
    int Get() { return g_; }

    // 转至下一Fibonacci项，O(1)
    int Next() { g_ += f_; f_ = g_ - f_; return g_; }

    // 转至上一Fibonacci项，O(1)
    int Prev() { f_ = g_ - f_; g_ -= f_; return g_; }

private:
    // f_ = fib(k - 1), g_ = fib(k)
    int f_, g_;
};

}   // utils

#endif // _FIB_HPP
