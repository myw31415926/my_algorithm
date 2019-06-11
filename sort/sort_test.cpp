/**
 * desc: 向量排序算法 
 * file: vector_sort.cpp
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

// print vector buffer
void Print(const int *buf, int num)
{
    std::cout << "vector = [";
    int i;
    for (i = 0; i < num - 1; i++) {
        std::cout << buf[i] << ", ";
    }
    std::cout << buf[i] << "]" << std::endl;
}

void Usage(const char* program)
{
    fprintf(stdout, "\nusage:\n");
    fprintf(stdout, "\t%s flag num\n", program);
    fprintf(stdout, "\tflag: \t1 - BubbleSort1\n");
    fprintf(stdout, "\t\t2 - BubbleSort2\n");
    fprintf(stdout, "\t\t3 - MergeSort\n");
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

    int* int_buf = new int[num];
    utils::Random(int_buf, num, 0xFFFF);    // 生成随机数，写入buf中

    switch (flag) {
        case 1:
            // Print(int_buf, num);
            sort::BubbleSort1(int_buf, 0, num);
            // std::cout << "****** BubbleSort1 ******" << std::endl;
            // Print(int_buf, num);
            break;

        case 2:
            // Print(int_buf, num);
            sort::BubbleSort2(int_buf, 0, num);
            // std::cout << "****** BubbleSort2 ******" << std::endl;
            // Print(int_buf, num);
            break;

        case 3:
            // Print(int_buf, num);
            sort::MergeSort(int_buf, 0, num);
            // std::cout << "****** MergeSort ******" << std::endl;
            // Print(int_buf, num);
            break;

        default:
            fprintf(stderr, "argument[flag] error\n");
            Usage(argv[0]);
    }

    return 0;
}
