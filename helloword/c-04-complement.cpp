//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C++ 补码
//============================================================================
#include <stdio.h>
#include <iostream>

/**
 * 定义函数
 * 二进制转无符号整型
 * @return
 */
unsigned int B2U(unsigned int num);

/**
 * 定义函数
 * 二进制转有符号整型
 * @param num
 * @return
 */
int B2T(int num);

int main() {
    std::cout << "测试输出" << std::endl;
    int i1 = 1;
    int i2 = -1;

    int i3 = B2U(i2);
    std::cout << i3 << std::endl;

    int i4 = B2T(0x000000000);

    std::cout << i4 << std::endl;
    return EXIT_SUCCESS;
}

/**
 * 实现函数
 * 二进制转无符号整型
 * @return
 */
unsigned int B2U(unsigned int num) {
    return (unsigned int)(num);
}

/**
 * 实现函数
 * 二进制转有符号整型
 * @param num
 * @return
 */
int B2T(int num) {

    return (int)(num);
}


