//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C++ 运算相关
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
//静态引入<iostream>包下std下的所有依赖
using namespace std;

// 声名test2()函数
void test2();

/**
 * 定义一个数据结构类名字叫Week
 */
typedef struct {
	// 星期日
	short Sunday = 0;
	// 星期一
	short Monday = 1;
	// 星期二
	short Tuesday = 2;
	// 星期三
	short Wedenesday = 3;
	// 星期四
	short Thursday = 4;
	// 星期五
	short Friday = 5;
	// 星期六
    short Saturday = 6;
} Week;

Week w;



int main() {
    test2();
	return EXIT_SUCCESS;
}




// 实现test2()函数
void test2() {
	int a=10;
	int b=20;
	// cout()函数打印输出，endl()函数输出换行和flush
	std::cout << a + b << std::endl;
	// 这个写法和上面的一致，因为我们已经静态引入了iostream下的std所有依赖
	cout << a - b << endl;
	cout << a * b << endl;
	// 除
	cout << a / b << endl;
	// 取模
	cout << a % b << endl;
	// 值++（先赋值再加加）
	cout << a++ << endl;
	// 值--（先赋值再减减）
	cout << b-- << endl;
    // ++值（先加加再赋值）
	cout << ++a << endl;
	// --值（先减减再赋值）
	cout << --b << endl;

	//---------------------------------------------//

    // sizeof是获取变量的字节大小
	cout << sizeof a << endl;
	// &a是指a变量在内存中的地址（也就是引用地址传递）
	cout << &a << endl;
    // *p = &a 是指获取变量a内存地址的值（注意：*var其实就是将获取变量var内存地址的值）
	int *p = &a;
	cout << *p << endl;
	// sizeof是获取变量的字节大小
	cout << sizeof(w) << endl;
	// 获取数据结构类的星期六的值
	cout << w.Saturday << endl;


	//------------返回0为false，1为true-------------//
    // 判断是否相等
	cout << (a == b) << endl;
	// 判断是否不相等
	cout << (a != b) << endl;
	// 判断是否大于
	cout << (a > b) << endl;
	// 判断是否小于
	cout << (a < b) << endl;
	// 判断是否小于等于
	cout << (a <= b) << endl;
	// 判断是否大于等于
    cout << (a >= b) << endl;


    // 逻辑运算&&（并且）
    cout << (a==12&&b==18) << endl;
    // 逻辑运算&&（并且）
    cout << (a==11&&b==20) << endl;
    // 逻辑运算||（或）
    cout << (a==11 || b==20) << endl;
    // 逻辑运算||（或）
    cout << (a==11 || b==18) << endl;

    //-----------位运算可参考JAVA的（https://github.com/firechiang/data-structure-test/blob/master/docs/bit-operation-desc.md）------------//
    cout << (11 | 10) << endl;
    cout << (11 & 9) << endl;

    //-----------赋值运算-------------------------//
    // a = a + b
    a += b;
    // a = a - b
    a -= b;
    // a = a / b
    a /= b;
    // a = a * b
    a *= b;
    // a = a % b
    a %= b;
    // a = a << b
    a <<= b;
    // a = a | b
    a |= b;
    // a = a & b
    a &= b;
}

