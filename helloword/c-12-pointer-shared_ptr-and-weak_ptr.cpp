//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C/C++ shared_ptr和 weak_ptr 智能指针相关
//============================================================================

#include <stdio.h>
#include <iostream>
#include <memory>

using namespace std;
void test1();
void test2();

/**
 * shared_ptr 指针被销毁时它所指向的对象会被自动销毁掉，一个shared_ptr指针可以共享给其它对象，它会有一个引用计数器，直到引用计数器为0时才会被销毁，内存才会被释放。
 * shared_ptr智能指针作用域范围：大括号里面shared_ptr指针引用增加了几次，出了大括号引用计数就会减几次，当引用计数为0时就会自动销毁掉，当然所指向的内存也会自动销毁。
 * 注意：这个类型的智能指针会有一些额外的内存开销，因为它自己维护了一个引用计数器
 * 缺陷：如果发生循环引用（像死锁一样）可能导致内存溢出，因为谁都不能释放谁
 *
 * weak_ptr 指针是协助 shared_ptr 指针工作的，以一种观察者模式工作，作用是协助 shared_ptr 工作，可获取资源的观察权，像旁观者一样观测资源的使用情况
 * 观察者意味着 weak_ptr 只能对 shared_ptr 进行引用，而不改变其引用计数，当 shared_ptr 实效后，相应的 weak_ptr 也会失效
 * 注意：weak_ptr 指针类型的变量可以之直接使用 shared_ptr 指针赋值，不会增加shared_ptr 指针的引用计数，也不会产生循环引用问题
 *
 * @return
 */
int main() {
    // shared_ptr智能指针的范围（注意：大括号里面shared_ptr指针引用增加了几次，出了大括号计数就会减几次，当引用计数为0时就会自动销毁掉，当然所指向的内存也会自动销毁）
    {
        // 申明一个shared_ptr指针变量名字叫p1，它所指向的是一个int类型的数据（注意：auto是自动推导类型，就像java11的var）
        auto p1 = std::shared_ptr<int>(new int(20));

        {
            // 申明一个shared_ptr指针变量名字叫p2，它所指向p1指针（注意：auto是自动推导类型，就像java11的var）
            auto p2 = p1;
            // 注意：p1和p2的引用计数都是2（原因：他们两个是同一个 shared_ptr 指针，每次被引用一次，引用计数就加1）
            cout << "p1的引用次数=" <<p1.use_count() << endl;
            cout << "p2的引用次数=" <<p2.use_count() << endl;
        }
        // 注意：到这里引用计数是1（原因：p2引用已经出了它的作用域，所以引用计数减1，最后得到1）
        cout << "再次打印p1的引用次数=" << p1.use_count() << endl;
    }

    cout << "------------------------------------------------------------------------------------------" << endl;

    // 演示 shared_ptr 指针，使用 std::move 转移所有权
    // shared_ptr智能指针的范围（注意：大括号里面shared_ptr指针引用增加了几次，出了大括号计数就会减几次，当引用计数为0时就会自动销毁掉，当然所指向的内存也会自动销毁）
    {

        // 申明一个shared_ptr指针变量名字叫p1，它所指向的是一个int类型的数据（注意：auto是自动推导类型，就像java11的var）
        auto p1 = std::shared_ptr<int>(new int(20));
        // 和上面的的语法同理
        //auto p1 = std::make_shared<int>(10);
        {
            // 申明一个shared_ptr指针变量名字叫p2并将p1指针的所有权交给它（注意：这个时候p1已经没有指向任何内存数据了（就是指向nullptr(空)），因为它的所有权已经交给p2了）
            auto p2 = std::move(p1);
            // 注意：p1的引用计数为0因为这个时候p1已经没有指向任何内存数据了（就是指向nullptr(空)），因为它的所有权已经交给p2了
            cout << "p1的引用次数=" <<p1.use_count() << endl;
            // 注意：p2的引用计数是1，就是自己嘛
            cout << "p2的引用次数=" <<p2.use_count() << endl;
            // 注意：get()函数是获取指针的内存地址
            cout << "p2指针所指向的数据=" << (*p2.get()) << endl;
        }
        // 注意：这个时候p1已经没有指向任何内存数据了（就是指向nullptr(空)），因为它的所有权已经交给p2了
        cout << "p1指针是否没有指向任何内存数据：" << ((p1 == nullptr) ? 1 : -1 ) << endl;

    }

    cout << "------------------------------------------------------------------------------------------" << endl;
    // 测试shared_ptr指针循环引用，最后内存不会被回收
    test1();
    cout << "-------------------------------------------------------------------------------------------" <<endl;
    // 测试使用weak_ptr指针来辅助shared_ptr指针循环引用，最后内存会被回收（注意：因为借助了weak_ptr指针所以循环引用不成立，所以会释放内存）
    test2();
    return EXIT_SUCCESS;
}

// 声明类（注意：struct是C语言声明类的方式，C++可以用class关键字来写）
struct B;
struct BW;

// 类
struct A {
    // 类成员变量是一个 shared_ptr 指针，它要指向的数据是B类型
    std::shared_ptr<B> pb;
    // 对象内存被释放时回调函数(注意：这个写法是固定的，类名再在前面加个～号)
    ~A(){
        cout << "~A()内存被回收" << endl;
    };
};

struct B {
    // 类成员变量是一个 shared_ptr 指针，它要指向的数据是A类型
    std::shared_ptr<A> pa;
    // 对象内存被释放时回调函数(注意：这个写法是固定的，类名再在前面加个～号)
    ~B() {
        cout << "~B()内存被回收" << endl;
    }
};

struct AW {
    // 类成员变量是一个 shared_ptr 指针，它要指向的数据是BW类型
    std::shared_ptr<BW> pb;
    // 对象内存被释放时回调函数(注意：这个写法是固定的，类名再在前面加个～号)
    ~AW(){
        cout << "~AW内存被回收" << endl;
    };

};

struct BW {
    // 类成员变量是一个 weak_ptr 指针，它要指向的数据是AW类型
    std::weak_ptr<AW> pa;
    // 对象内存被释放时回调函数(注意：这个写法是固定的，类名再在前面加个～号)
    ~BW(){
        cout << "~BW内存被回收" << endl;
    };

};

/**
 * 测试shared_ptr指针循环引用，最后内存不会被回收（因为产生了循环引用所以函数执行完毕不会释放内存，可能导致内存溢出）
 */
void test1() {
    // 声明shared_ptr指针变量ta和tb，一个指向A类型的数据，一个指向B类型的数据
    std::shared_ptr<A> ta(new A());
    std::shared_ptr<B> tb(new B());
    // 打印两个指针的引用计数次数
    cout << "test1()函数里面ta的引用计数次数=" << ta.use_count() << endl;
    cout << "test1()函数里面tb的引用计数次数=" << tb.use_count() << endl;

    // 给ta对象里面的pb成员变量赋值
    ta -> pb = tb;
    // 给tb对象里面的pa成员变量赋值
    tb -> pa = ta;
    // 注意：他们两个的引用计数都是2，因为他们2个在上一步都加了一次引用计数
    cout << "test1()函数里面tb的引用计数次数=" << ta.use_count() << endl;
    cout << "test1()函数里面ta的引用计数次数=" << tb.use_count() << endl;
}

/**
 * 测试使用weak_ptr指针来辅助shared_ptr指针循环引用，最后内存会被回收（注意：因为借助了weak_ptr指针所以循环引用不成立，所以函数执行完毕释放内存）
 */
void test2() {
    // 声明shared_ptr指针变量ta和tb，一个指向A类型的数据，一个指向B类型的数据
    std::shared_ptr<AW> ta(new AW());
    //（当前函数执行完毕，引用tb计数减1）
    std::shared_ptr<BW> tb(new BW());
    // 打印两个指针的引用计数次数
    cout << "test2()函数里面ta的引用计数次数=" << ta.use_count() << endl;
    cout << "test2()函数里面tb的引用计数次数=" << tb.use_count() << endl;

    // 给ta对象里面的pb成员变量赋值（当前函数执行完毕，引用tb计数减1）
    ta -> pb = tb;
    // 给tb对象里面的pa成员变量赋值
    tb -> pa = ta;
    // 注意：ta的引用计数是1（原因：tb对象里面的pa成员变量是weak_ptr指针，它可以看成是shared_ptr指针，但不会增加shared_ptr指针的引用计数）
    cout << "test2()函数里面ta的引用计数次数=" << ta.use_count() << endl;
    cout << "test2()函数里面tb的引用计数次数=" << tb.use_count() << endl;
}

