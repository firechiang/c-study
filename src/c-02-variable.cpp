//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C++ 变量声明相关
//============================================================================

#include <stdio.h>
#include <stdlib.h>

// 声明函数头
void test1();
// 不指定类型定义变量
#define AAA_AAA = "sdasda";
// 指定类型定义常量（推荐使用这种方式）
const long int L_L = 10;


/*int main() {
	printf("L_L=%ld\n",L_L);
	test1();
	return EXIT_SUCCESS;
}*/

// 实现函数
void test1() {
	// 不指定类型定义变量
    #define aaa = "sadada";
	// 指定类型指定变量（推荐这种方式定义变量）
	long int n = 99;
	printf_s("sdasda=%d",n);
}



