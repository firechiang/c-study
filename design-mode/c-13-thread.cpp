//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C++ Thread相关（多线程相关）
//============================================================================

#include <thread>
#include <stdio.h>
#include <iostream>
// 互斥排它锁
#include <mutex>

using namespace std;
/**
 * 线程执行函数
 * @param g 锁对象的引用
 */
void T1(mutex& g) {
    // 加锁
    g.lock();
    // 尝试获取锁
    // g.try_lock();
    cout << "线程1" << endl;
    // 释放锁
    g.unlock();
}

int main() {
    // 锁对象
    mutex g_mutex;
    /**
     * 创建线程并执行
     * @param __f    线程执行函数
     * @param __args 线程执行函数的参数
     */
    thread t1(T1,ref(g_mutex));
    // 等待线程t1执行完成
    t1.join();

    //------lambda表达式的方式创建并执行线程-----------------//
    thread t2([](){
        cout << "线程2" << endl;
    });
    //
    thread t3([](){
        cout << "线程3" << endl;
    });
    cout << "交换前线程2的ID=" << t2.get_id() << endl;
    cout << "交换前线程3的ID=" << t3.get_id() << endl;
    // 交换两个线程（将两个线程对象进行交换）
    swap(t2,t3);
    cout << "交换后线程2的ID=" << t2.get_id() << endl;
    cout << "交换后线程3的ID=" << t3.get_id() << endl;

    t2.join();
    t3.join();
    return EXIT_SUCCESS;
}

