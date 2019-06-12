/**
 * desc: 向量搜索算法测试
 * file: search_test.cpp
 *
 * author:  myw31415926
 * date:    20190611
 * version: V0.1
 *
 * the closer you look, the less you see
 */

#include <cstdio>
#include "search.hpp"
#include "utils.hpp"

#define _DEBUG 1

// print vector buffer
void Print(const int *elem, int num)
{
#ifdef _DEBUG
    std::cout << "vector = [";
    int i;
    for (i = 0; i < num - 1; i++) {
        std::cout << elem[i] << ", ";
    }
    std::cout << elem[i] << "]" << std::endl;
#endif
}

void Usage(const char* program)
{
    fprintf(stdout, "\nusage:\n");
    fprintf(stdout, "\t%s flag target\n", program);
    fprintf(stdout, "\tflag: \t1 - BinSearch\n");
    fprintf(stdout, "\t\t2 - FibSearch\n");
}

// main
int main(int argc, char *argv[])
{
    int flag, target; 

    if (argc != 3) {
        fprintf(stderr, "argument error\n");
        Usage(argv[0]);
        return -1;
    }

    flag   = atoi(argv[1]);
    target = atoi(argv[2]);

    const int num = 10;
    int elem[num] = {2, 4, 5, 7, 7, 8, 8, 8, 9, 10};

    switch (flag) {
        case 1:
            Print(elem, num);
            std::cout << "BinSearch ret = " 
                      << search::BinSearch(target, elem, 0, num) << std::endl;
            break;

        case 2:
            Print(elem, num);
            std::cout << "BinSearch ret = " 
                      << search::BinSearch(target, elem, 0, num) << std::endl;
            break;

        default:
            fprintf(stderr, "argument[flag] error\n");
            Usage(argv[0]);
    }

    return 0;
}
