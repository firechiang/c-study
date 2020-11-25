//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C/C++ unique_ptr 智能指针相关
//============================================================================

#include <stdio.h>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

/**
 *  unique_ptr智能指针的范围（注意：出了这个大括号 unique_ptr 指针自动销毁掉，当然所指向的内存也会自动销毁）
 *  unique_ptr指针被销毁时它所指向的对象会被自动销毁掉，一个unique_ptr指针只能被一个对象持有，不支持复制和重新赋值，但是可以使用 std::move 转移所有权
 * @return
 */
int main() {

    // unique_ptr智能指针的范围（注意：出了这个大括号 unique_ptr 指针自动销毁掉，当然所指向的内存也会自动销毁）
    // unique_ptr指针被销毁时它所指向的对象会被自动销毁掉，一个unique_ptr指针只能被一个对象持有，不支持复制和重新赋值，但是可以使用 std::move 转移所有权
    {
        // 申明一个unique_ptr指针变量名字叫p1，它所指向的是一个int类型的数据（注意：auto是自动推导类型，就像java11的var）
        auto p1 = std::make_unique<int>(10);
        // 和上面的的语法同理
        //auto p1 = std::unique_ptr<int>(new int(10));
        // 打印unique_ptr指针所指向的数据(注意：get()函数获取unique_ptr指针所指向的内存地址)
        cout << (*p1.get()) << endl;
        // 注意：放开注释报错。原因：一个unique_ptr指针只能被一个对象持有，不支持复制和重新赋值
        //auto p2 = p1;
        // 将unique_ptr智能指针的所有权转移给p2（注意：auto是自动推导类型，就像java11的var）
        auto p2 = std::move(p1);
        // 打印unique_ptr指针所指向的数据(注意：get()函数获取unique_ptr指针所指向的内存地址)
        cout << (*p2.get()) << endl;
        // 注意：p1 的内存地址变为nullptr（空），因为它的所有权被转移了，就没有在指向任何内存地址了
        cout << (p1.get() == nullptr ? 1 : 0) << endl;
    }
    return EXIT_SUCCESS;
}

