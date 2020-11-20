//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C/C++ 指针相关
//============================================================================

#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int a=10,b=30;
    // 定义一个指针变量，其实就是定义一个变量指向一块内存地址（注意：&就是取内存地址）
    int* d = &a;
    int* c = &b;

    // 定义一个数组
    int arrayInt[] = {1,2,4,5};
    char strArray[] = {"asdasdasdasda"};

    // 定义一个指针数组（就是这个数组里面存的是指针）
    int* array[4] = {&a,&b};
    // 定义一个数组的指针，就是定义一个指针指向一个包含4个元素的数组，指针的名字叫array1（注意：加括号的是指针，没加括号的是数组）
    int(*array1)[4] = &arrayInt;

    // 注意：const关键字表示不可变（如果有多个const以和变量名最近的那个const为基准），被它修饰的是不可修改的(注意：const修饰规则（就是优先级）是先修饰const左边部分，如果左边没有，就是修饰const右边部分)
    // 定义一个被const修饰的指针变量（注意：这里const修饰的是char，也就是指针变量的值不能修改，但是指针的指向可以被修改）
    char const *str1 = "asdasdsada";
    // 看 修改了指针的指向不报错
    str1 = strArray;

    // 定义一个被const修饰的指针变量（注意：这里const修饰的是×，也就是指针的指向不能被修改，但是指针变量的值可以被修改）
    char* const str2 = "454545151545";
    // 注释放开报错（因为指针的指向不能被修改）
    //str2 = "asdasd";
    cout << str2 << endl;

    // 定义一个被const修饰的指针变量（注意：这里const修饰的是×，也就是指针的指向不能被修改，但是指针变量的值可以被修改）
    // 注意：const关键字表示不可变（如果有多个const以和变量名最近的那个const为基准），被它修饰的是不可修改的(注意：const修饰规则（就是优先级）是先修饰const左边部分，如果左边没有，就是修饰const右边部分)
    char const* const str = "sadasdasda";
    // 注释放开报错（因为指针的指向不能被修改）
    //str = strArray;

    //------------演示建立一个指向指针的指针变量------------------------//
    int aint = 10;
    // 定义一个指针变量（指向变量a）
    int* aint1 = &a;
    // 定义一个指针变量，它指向一个指针
    int** aint2 = &aint1;
    // 定义一个指针并初始化，但是没有指向任何内存（）
    int* bint = NULL;
    // 指针不为空
    if(bint != NULL) {
        // 将指针至为空
        bint = NULL;
    }

    int dint = 10;
    // 定义一个指针变量，指向一个int类型的变量
    int *dintx = &dint;
    cout << dintx << endl;
    // 获取指针里面的数据并加1
    int gint = *dintx + 1;
    cout << gint << endl;
    // 指针变量加1（就是指向该指针后面的一块内存地址（注意：这一快内存就是该指针后面的4个字节的内存地址（因为1个int类型占4个字节））），再取加1后内存地址的值（就是取该指针后4个字节内存里面的值）
    // 注意：指针运算加N实际上是将指针向后移动到N个指针的数据类型所占的内存空间（比如：int类型的指针加1,就是将指针移动并指向后4个字节所在的内存地址，因为1个int类型占4个字节）
    int ss = *(dintx + 1);
    // 打印后4个字节内存地址的值
    cout << ss << endl;

    int hh=1,kk=2,ll;
    // 等同于 hh++ 在+kk;(就是：先将hh的值赋给ll，hh再加加，最后ll=ll+kk=3)
    //ll = hh+++kk;
    // 等同于hh++ + ++kk;(就是：先将hh的值赋给ll，hh再加加，再kk加加，最后ll=ll+(++kk)=4)
    ll = hh++ + ++kk;

    int oo = 1212;
    int* pp = &oo;
    // 先是pp的指针++，再取指针++后所指向内存地址的数据（注意：这个数据是什么我们也不知道，因为这个地址我们没有往里面放数据），再数据++，最后赋值给llll
    int llll = ++*++pp;
    cout << llll << endl;
    return EXIT_SUCCESS;
}

