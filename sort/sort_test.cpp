/**
 * desc: 向量排序算法测试
 * file: sort_test.cpp
 *
 * author:  myw31415926
 * date:    20190604
 * version: V0.1
 *
 * the closer you look, the less you see
 */

#include <cstdio>
#include "sort.hpp"
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
    fprintf(stdout, "\t%s flag num\n", program);
    fprintf(stdout, "\tflag: \t1 - BubbleSort1; 101 - BubbleSort1 no print\n");
    fprintf(stdout, "\t\t2 - BubbleSort2; 102 - BubbleSort2 no print\n");
    fprintf(stdout, "\t\t3 - MergeSort; 103 - MergeSort no print\n");
}

// main
int main(int argc, char *argv[])
{
    int flag, num; 

    if (argc != 3) {
        fprintf(stderr, "argument error\n");
        Usage(argv[0]);
        return -1;
    }

    flag = atoi(argv[1]);
    num  = atoi(argv[2]);

    int* elem = new int[num];
    utils::Random(elem, num, 0xFFFF);    // 生成随机数，写入buf中

    switch (flag) {
        case 1:
            Print(elem, num);
            sort::BubbleSort1(elem, 0, num);
            std::cout << "****** BubbleSort1 ******" << std::endl;
            Print(elem, num);
            break;

        case 101:
            sort::BubbleSort1(elem, 0, num);
            break;

        case 2:
            Print(elem, num);
            sort::BubbleSort2(elem, 0, num);
            std::cout << "****** BubbleSort2 ******" << std::endl;
            Print(elem, num);
            break;

        case 102:
            sort::BubbleSort2(elem, 0, num);
            break;

        case 3:
            Print(elem, num);
            sort::MergeSort(elem, 0, num);
            std::cout << "****** MergeSort ******" << std::endl;
            Print(elem, num);
            break;

        case 103:
            sort::MergeSort(elem, 0, num);
            break;

        default:
            fprintf(stderr, "argument[flag] error\n");
            Usage(argv[0]);
    }

    return 0;
}
