//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C/C++ 宏定义相关
//============================================================================
#include <stdio.h>
using namespace std;
// 防止重复引入依赖(注意：这个好像只能在Windows上起作用)
#pragma once


#ifndef AAA_AAA  // 如果 AAA_AAA 不存在就执行下面的定义逻辑
#define AAA_AAA  // 定义一个宏，名字叫 AAA_AAA
// 宏定义里面的代码
#include <iostream>

#endif

int main() {
    cout << "ce" << endl;
    return EXIT_SUCCESS;
}



