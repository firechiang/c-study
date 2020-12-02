//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C/C++ 函数以及函数指针相关
//============================================================================

#include <stdio.h>
#include <iostream>

using namespace std;
// 返回int类型的函数
int test(int a);
// 求和
int test1(int a,int b) ;
// 参数m是一个函数指针，它指向一个返回值是int类型，两个参数也是int类型的函数
int test2(int(*m)(int a,int b));
/**
 * 内联函数(注意：加了inline关键字的是内联函数，还有内联函数在编译时，编译器会把该函数的代码（汇编代码）副本放置在每个调用该函数的地方，以提高函数的调用速度（空间换时间）)
 * 缺点：内联函数进行任何修改，都需要重新编译函数的所有客户端，因为编译器需要重新更换一次所有的代码，否则将会继续使用旧的函数
 * 内联函数应用场景：
 * 1，一个函数不断地被重复调用（函数体小适宜）
 * 2，函数只有简单几行，且函数不包括for,while,switch语句。
 */
inline void test3();

// 在aaa命名空间下创建一个函数
namespace aaa {

    void test();
}

int main() {
    cout << "测试打印" << endl;

    // 定义一个函数指针变量p（注意：第一个int表示要指向函数的返回值类型（就是函数的返回值类型）,第二个int表示要指向函数的参数类型（就是函数的参数类型））
    int(*p)(int);
    // 给函数指针赋值（就是让他等于某个函数）
    p = test;
    // 调用函数指针所指向的函数
    int count = (*p)(2);
    cout << "我是count=" << count << endl;

    // 定义一个函数指针变量p1（注意：第一个int表示要指向函数的返回值类型（就是函数的返回值类型）,后面的两个int表示要指向函数的参数类型（就是函数的参数类型））
    int(*p1)(int a,int b) = test1;
    // 调用函数指针所指向的函数
    int ab = (*p1)(5,5);
    cout << "我是ab=" << ab << endl;

    int ac = test2(p1);
    cout << "我是ac=" << ac << endl;
    // 调用aaa命名空间下的test()函数
    aaa::test();
    test3();
    return EXIT_SUCCESS;
}

// 返回int类型的函数
int test(int a) {

    return ++a;
}

// 求和
int test1(int a,int b) {

    return a + b;
}

// 参数m是一个函数指针，它指向一个返回值是int类型，两个参数也是int类型的函数
int test2(int(*m)(int a,int b)) {
    // 调用函数指针所指向的函数
    return (*m)(6,6);
}

/**
 * 内联函数(注意：加了inline关键字的是内联函数，还有内联函数在编译时，编译器会把该函数的代码（汇编代码）副本放置在每个调用该函数的地方，以提高函数的调用速度（空间换时间）)
 * 缺点：内联函数进行任何修改，都需要重新编译函数的所有客户端，因为编译器需要重新更换一次所有的代码，否则将会继续使用旧的函数
 * 内联函数应用场景：
 * 1，一个函数不断地被重复调用（函数体小适宜）
 * 2，函数只有简单几行，且函数不包括for,while,switch语句。
 */
inline void test3() {
    cout << "调用了内联函数test3()" << endl;
}

// 实现aaa命名空间下的函数
namespace aaa {

    void test() {
        cout << "调用了aaa命名空间下的test()函数" << endl;
    }
}




