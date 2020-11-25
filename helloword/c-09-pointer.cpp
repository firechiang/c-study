//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C/C++ 堆内存分配和释放相关
//============================================================================

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    // 定义一个指针变量，new关键字分配内存
    int* i1 = new int(10);
    // 定义一个指针变量，malloc关键字分配内存
    int* i2 = (int*)malloc(10);

    // 使用delete关键字释放new关键字分配的内存
    if(i1  != NULL) {
        delete i1;
    }

    // 使用free()函数释放malloc()函数分配的内存
    if(i2 != NULL) {
        free(i2);
    }
    cout << "内存分配与释放演示完毕" << endl;
    return EXIT_SUCCESS;
}