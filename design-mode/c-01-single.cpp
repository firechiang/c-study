//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C++ 设计模式（单立模式）
//============================================================================

#include <stdio.h>
#include <iostream>

using namespace std;

/**
 * 定义一个类（struct定义的类成员默认是public的，class定义的类成员默认是private的，其它没有区别）
 */
class SingleInstance {
    /**
     * 构造和释构函数都是私有的防止外界调用
     */
    private:
        SingleInstance();
        ~SingleInstance();
        /**
         * 静态私有的成员变量（注意：static 修饰的变量是全局的且随着程序开始而初始化分配内存，随着程序退出而释放内存）
         */
        static SingleInstance* instance;

    /**
     * 静态获取实列的函数（注意：const表示全局不可变的的）
     */
    public:
        static const SingleInstance* getInstance();
        /**
         * 打印当前对象的指针地址
         */
        static void print() {
            cout << "SingleInstance=" << instance << endl;
        }
};

/**
 * 初始化 SingleInstance 类里面的 instance 成员变量。让其等于NULL
 */
SingleInstance* SingleInstance::instance = NULL;
/**
 * 实现构造和释构函数（注意：这两个函数必须得实现否则 SingleInstance 不能new）
 */
SingleInstance::SingleInstance() {}
SingleInstance::~SingleInstance() {}
/**
 * 实现SingleInstance类里面getInstance()函数
 * @return
 */
const SingleInstance* SingleInstance::getInstance() {
    if(!instance) {
        instance = new SingleInstance();
    }
    return instance;
}


int main() {
    // 获取到对象实列后调用 print()函数（注意：-> 一般用于成员提取(适用于指针)，比如 A -> B 就相当于JAVA的 A.B（也就是获取A对象里面的B变量） 当然如果B是函数就会去调用B函数）
    SingleInstance::getInstance() -> print();
    return EXIT_SUCCESS;
}