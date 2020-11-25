//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C/C++ 引用相关
//============================================================================

#include <stdio.h>
#include <iostream>
#include <assert.h>

using namespace std;
// 交换a，b两个引用所指向内存里面的值
void test1(int& a,int& b);

// 交换a，b两个指针所指向的内存地址
void test2(int* a,int* b);

/**
 * 引用可以看着是一种特殊的指针，不允许修改的指针（注意：引用不存在空引用，因为它必须初始化，一个引用永远指向它初始化的那个内存）
 * 注意：引用作为参数传递的时候可以直接写变量名，而不需要用&符号获取内存地址（详情见test1()函数的调用），而且获取值的时候可以直接使用变量名，而不需要使用*号取内存地址里面的值
 * @return
 */
int main() {
    int x1 = 1,x2 = 2;
    // 定义一个引用指向x1(注意：定义引用使用&符号)
    int& rx = x1;
    // 修改引用的值（注意：这个修改是修改rx引用所指向内存里面的值）
    rx = 2;
    // 现在x1和rx都是2（原因：x1所指向内存里面的数据被rx引用修改成2了（x1和rx所指向的是同一个内存地址））
    cout << x1 << endl;
    cout << rx << endl;

    int aa = 20,bb = 30;
    // 交换aa，bb两个引用所指向内存里面的值
    test1(aa,bb);
    assert(aa == 30 && bb == 20);

    int cc = 50,dd = 60;
    // 交换cc，dd两个指针所指向的内存地址
    test2(&cc,&dd);
    assert(cc == 60 && dd == 50);
    return EXIT_SUCCESS;
}

/**
 * 交换a，b两个引用所指向内存里面的值
 * @param a
 * @param b
 */
void test1(int& a,int& b) {
    int temp = a;
    a = b;
    b = temp;
}

/**
 * 交换a，b两个指针所指向的内存地址
 * @param a
 * @param b
 */
void test2(int* a,int* b) {
    // 定义临时变量记录a指针地址
    int temp = *a;
    // 修改a指针地址为b指针所指向的地址
    *a = *b;
    // 修改a指针地址为temp
    *b = temp;
}

