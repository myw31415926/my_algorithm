/**
 * desc: 斐波那契数列算法 
 * file: fibonacci.c
 *
 * author:  myw31415926
 * date:    20190424
 * version: V0.1
 *
 * the closer you look, the less you see
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>    // printf uint64_t(PRIu64)

/* 算法1：递归，时间复杂度 O(2^n) */
uint64_t fib_recurse(int n)
{
    return (n < 2) ? n : fib_recurse(n - 2) + fib_recurse(n - 1);
}

/******************************************************/
/**
 * 递归过程
 * fib(4, prev) pprev                               // fib(4, prev) = 3
 *          |       |
 *         fib(3, prev) + pprev                     // prev = 2, pprev = 1
 *                  |       |
 *                 fib(2, prev) + pprev             // prev = 1, pprev = 1
 *                          |       |
 *                         fib(1, prev) + pprev     // prev = 0, pprev = 1 
 *                                  |       |
 *                                 fib(0, prev)     // prev = 1
 *
 * 即 prev = fib(n - 1); pprev = fib(n - 2)
 */
static uint64_t _line_recurse(int n, uint64_t *prev)
{
    uint64_t pprev;
    if (n == 0) {    // 终止条件 fib(0)  = 0
        *prev = 1;   // 当n为0时，可认为 prev = fib(-1) = 1
        return 0;
    } else {
        *prev = _line_recurse(n - 1, &pprev);
        return *prev + pprev;
    }
}

/* 算法2：线性递归，也叫记忆法，记录上一次的计算结果。时间复杂度 O(n) */
uint64_t fib_line_recurse(int n)
{
    uint64_t prev = 0;
    return _line_recurse(n, &prev);
}

/******************************************************/
/* 算法3：动态规划，自小而大进行计算，复杂度 O(n) */
uint64_t fib_dynamic(int n) 
{
    uint64_t pprev = 1, prev = 0;   // fib(-1) = 1, fib(0) = 0
    uint64_t tmp;

    while (n-- > 0) {
        tmp   = prev + pprev;
        pprev = prev;
        prev  = tmp;
        /**
         * 另一种方法
         * prev  = prev + pprev;
         * pprev = prev - pprev;
         */
    }

    return prev;
}

/******************************************************/
/* 算法4：静态存储法，通过计算将fibonacci数列存入数组中，以备查询 */
#define FIB_SIZE 64
static uint64_t g_fib_array[FIB_SIZE] = {0};

static void _fib_init(int fib_size)
{
    int i = 0;
    g_fib_array[0] = 0;
    g_fib_array[1] = 1;
 
    for (i = 2; i < fib_size; i++) {
        g_fib_array[i] = g_fib_array[i - 1] + g_fib_array[i - 2];
    }
}

/* 算法5：通项公式算法。计算机不能真正表示无理数，此算法在没有意义 */


/* 算法6：矩阵求解 */
/* fibonacci数列矩阵 */
typedef struct matrix_t {
    uint64_t m[2][2];
} matrix_t;

/* 矩阵乘法 */
matrix_t matrix_multi(const matrix_t a, const matrix_t b)
{
    int i, j, k;
    matrix_t ret;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            ret.m[i][j] = 0;
            for (k = 0; k < 2; k++) {
                ret.m[i][j] += a.m[i][k] * b.m[k][j];
            }
        }
    }

    return ret;
}

/* 计算矩阵的n次幂 */
uint64_t fib_matrix(int n)
{
    static matrix_t base;
    matrix_t ret;

    /* base 初始化为基矩阵 */
    base.m[0][0] = base.m[0][1] = base.m[1][0] = 1;
    base.m[1][1] = 0;
    /* ret 初始化为单位矩阵 */
    ret.m[0][0]  = ret.m[1][1]  = 1;
    ret.m[0][1]  = ret.m[1][0]  = 0;

    while (n > 0) {
        if (n & 1) {
            ret = matrix_multi(base, ret);
        }

        base = matrix_multi(base, base);
        n >>= 1;
    }

    // fprintf(stdout, "\t%ju, %ju \n", ret.m[0][0], ret.m[0][1]);
    // fprintf(stdout, "\t%ju, %ju \n", ret.m[1][0], ret.m[1][1]);

    return ret.m[1][0];
}

/* main */
int main(int argc, char *argv[])
{
    int flag, num; 

    if (argc != 3) {
        fprintf(stderr, "argument error\n");
        fprintf(stdout, "\nusage:\n");
        fprintf(stdout, "\t%s flag[1|2|3|6] number\n", argv[0]);
        return -1;
    }

    flag = atoi(argv[1]);
    num  = atoi(argv[2]);

    switch (flag) {
        case 1:
            fprintf(stdout, "fib(%d) = %"PRIu64"\n", num, fib_recurse(num));
            break;

        case 2:
            fprintf(stdout, "fib(%d) = %"PRIu64"\n", num, fib_line_recurse(num));
            break;

        case 3:
            fprintf(stdout, "fib(%d) = %"PRIu64"\n", num, fib_dynamic(num));
            break;

        case 6:
            fprintf(stdout, "fib(%d) = %"PRIu64"\n", num, fib_matrix(num));
            break;

        default:
            fprintf(stderr, "argument[flag] error\n");
    }

    return 0;
}
