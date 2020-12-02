//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C/C++ 语法练习
//============================================================================

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

/**
 * 判断是否闰年
 * @param year
 * @return
 */
bool isLeapYear(int year);

int main () {
    int year = 2020;
    cout << year <<"年是否是闰年:" << (isLeapYear(year)) << endl;

    // 函数里面定义枚举类型（注意：默认情况下第一个等于0，第二个等于1。像数组下标一样，就是xx=0,aa=1,ss=2）
    enum AAA{xx,aa,ss};
    // 枚举类型a等于枚举xx
    AAA a = aa;
    cout << a << endl;


    float f1 = 3.000;
    // 判断是否整型数值
    if((f1 - (int)f1) == 0) {
        cout << "f1是整型数值" << endl;
    }
    return EXIT_SUCCESS;
}

/**
 * 判断是否闰年
 * @param year
 * @return
 */
bool isLeapYear(int year) {
    if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        return true;
    }
    return false;
}


/**
 * C++的方式定义枚举类型（注意：默认情况下第一个等于0，第二个等于1。像数组下标一样，下面的是我们给了自定义的值）
 */
typedef enum TYRR {
    A=1,
    B=2,
    C=3
};

/**
 * 定义一个联合体（就是数据结构）
 * 各成员共用一块内存空间，并且同时只有一个成员可以得到这块内存的使用权(对该内存的读写)，各变量共用一个内存首地址。
 * 因而，联合体比结构体更节约内存。一个union变量的总长度至少能容纳最大的成员变量，而且要满足是所有成员变量类型大小的整数倍。不允许对联合体变量名U2直接赋值或其他操作。
 */
union Address {
    // ip
    string ip;
    // 域名
    string hostname;
};

/**
 * 定义一个结构体（就是数据结构）
 * 各成员各自拥有自己的内存，各自使用互不干涉，同时存在的，遵循内存对齐原则。一个struct变量的总长度等于所有成员的长度之和
 */
struct User {
    // 姓名
    string name;
    // 年龄
    int age;
    /**
     * 嵌入的结构体
     */
    Address a;
};



