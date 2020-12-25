//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C++ 设计模式（观察者模式）
//============================================================================

#include <stdio.h>
#include <iostream>
#include <list>
#include <string>

using namespace std;

/**
 * 用宏将代码包裹起来，那么里面的代码将是全局唯一的
 */
# ifndef OBSERVER_H_1
# define OBSERVER_H_1
/**
 * 被观察对象
 */
struct Observer {

public:
    /**
     * 构造器
     */
    Observer(){;};
    /**
     * 释构函数
     */
    virtual ~Observer(){;};
    /**
     * 行为函数
     * 注意：virtual（表示可重写的），等于0表示该函数没有实现体需要子类重写实现
     * void*指针不指向任何数据类型，就像JAVA的Object一样，因此如果要访问实际存在的数据，必须将void*指针强转成为指定一个确定的数据类型的数据，如int*、string*、char*等
     *
     * void*指针只支持几种有限的操作：
     * 1，与另一个指针进行比较；
     * 2，向函数传递void*指针或从函数返回void*指针；
     * 3，给另一个void*指针赋值。不允许使用void*指针操作它所指向的对象，例如，不允许对void*指针进行解引用。不允许对void*指针进行算术操作
     * @param pArg
     */
    virtual void action(void* pArg) = 0;
};

/**
 * 观察者
 */
struct Observerable {
    private:
        /**
         * 被观察对象
         */
        list<Observer*> _Obses;
    public:
        /**
         * 构造器
         */
        Observerable(){;};
        /**
         * 释构函数
         */
        ~Observerable(){;};

        /**
         * 注册被观察者
         */
        void add(Observer* obs) {
            if(obs != NULL) {
                /**
                 * 获取到集合里面的第一个元素
                 * 注意：auto 是自动推导返回值类型
                 */
                auto it = _Obses.begin();
                // 如果没有遍历到最后
                for(;it != _Obses.end();it++) {
                    // 如果在集合里面已经有了就直接返回
                    if(obs == *it) {
                        return;
                    }
                }
                /**
                 * 将被观察者对象添加到集合的尾部
                 */
                _Obses.push_back(obs);
            }
        }

        /**
         * 移除被观察者对象
         * @param obs
         */
        void remove(Observer* obs) {
            // 被移除的对象为空或者集合为空就直接返回
            if(obs == NULL || _Obses.empty()) {
                return;
            }
            _Obses.remove(obs);
        }
        /**
         * 通知被观察者对象
         * @param pArg
         */
        void notify(void* pArg) {
            auto it = _Obses.begin();
            for(;it != _Obses.end();it++) {
                // 调用被观察者对象里面的action()函数（注意：-> 和 . 意思差不多。但是->可以调用被重写的函数。而. 不行 . 只能调用实际已经定义被实现的函数）
                (*it) -> action(pArg);
            }
        }
};
# endif

/**
 * 被观察对象 User1 继承 Observer
 * 注意：public 表示父类里面的函数是public的在子类里面还是public
 */
struct User1: public Observer {
    /**
     * 重写父类的行为函数
     * 注意：override 表示重写
     * @param pArg
     */
    void action(void *pArg) override {
        // 注意：pArg 只所以可以强制转换为 char*(char引用)是因为我们本身传递的就是 char类型
        cout << "User1被执行了，参数=" << (char*)pArg << endl;
    }
};

/**
 * 被观察对象 User2 继承 Observer
 * 注意：public 表示父类里面的函数是public的在子类里面还是public
 */
struct User2: public Observer {
    /**
     * 重写父类的行为函数
     * 注意：override 表示重写
     * @param pArg
     */
    void action(void* pArg) override {
        // 注意：pArg 只所以可以强制转换为 char*(char引用)是因为我们本身传递的就是 char类型
        cout << "User2被执行了，参数=" << (char*)pArg << endl;
    }
};

int main() {
    User1 user1;
    User2 user2;

    Observerable o;
    // 将被观察者对象添加到观察者
    o.add(&user1);
    o.add(&user2);
    string arg = "sdasadada";
    // 通知被观察者对象（注意：参数是 arg 并且被强制转换为 void* 指针）
    o.notify((void*)arg.c_str());
    // 移除被观察者对象user1
    o.remove(&user1);
    // 通知被观察者对象（注意：参数是 arg 并且被强制转换为 void* 指针）
    o.notify((void*)arg.c_str());
    return EXIT_SUCCESS;
}



