//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C/C++ 面向对象相关
// 注意：struct定义的类成员默认是public的，class定义的类成员默认是private的，其它没有区别
//============================================================================

#include <stdio.h>
#include <iostream>
using namespace std;

/**
 * 定义一个类（struct定义的类成员默认是public的，class定义的类成员默认是private的，其它没有区别）
 */
struct Person {
// public说明下面成员和函数都是供有的
public:
    string name;
    int age = 1;
    // 无参构造器
    Person() {
        cout << "Person被创建了" << endl;
    }
    // 有参构造器
    Person(const string& name,int age) {
        cout << "Person被创建了" << endl;
        Person::name = name;
        Person::age = age;
    }

    // 有参构造器(注意：这个写法和上面的差不多就是使用 name(name) 这种方式来赋值)
    Person(const string &name,int age,double abs): name(name),age(age),abs(abs) {

    }
    /**
     * 拷贝构造器（就是对象初始化时没有调用构造器，而是拷贝了其它对象的内容，就会调用这个拷贝构造器）
     * 注意：如果变量之前没有定义，而是直接定义并将其它对象赋给它且没有运算符相关操作，比如(Person p1 = p)就会使用拷贝构造器构造
    * @param p
    */
    Person(const Person& person) {
        name = person.name;
        age = person.age;
        cout << "触发了拷贝构造器" << endl;
    }

    /**
     * 运算符重载函数（就是可以让两个对象使用+号运算），注意：const Person& 表示参数p的引用不允许被修改
     * @param p
     * @return
     */
    Person operator+(const Person& p) {
        Person temp;
        temp.age = age + p.getAge();
        temp.name = name + p.getName();
        cout << "两个对象正在相加" << endl;
        // 这钟写法和上面的一样
        //return Person(name + p.getName(),age + p.getAge());
        return temp;
    }

    /**
     * 运算符重载函数（就是可以让两个对象使用=号运算赋值（这个函数一般不需要重写默认就有）），注意：const Person& 表示参数p的引用不允许被修改
     * @param p
     * @return
     */
    Person& operator=(const Person& p) {
        // 不是同一个地址（注意：this是指向自己的一个指针）
        if(this != &p) {
            age = p.getAge();
            name = p.getName();
        }
        cout << "正在使用=号使用赋值" << endl;
        // 返回自己的引用（注意：this是指向自己的一个指针）
        return *this;
    }

    // 释构函数，就是对象内存被回收时调用（注意：释构函数是固定写法就是类名前面再加个～，还有virtual关键字表示该函数可以被重写）
    virtual ~Person() {
        cout << "age=" << age <<"的Person被销毁了" << endl;
    }

    /**
     * const 表示在函数的内部name的值不允许被改变
     * @return
     */
    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

// private说明下面成员和函数都是私有的
private:
    double abs;
    // 定义 getAbs() 函数，注意实现写在下面（注意：const 表示该返回值在函数内部不可以被修改）
    double getAbs() const;
};

int main() {
    cout << "程度地方" << endl;
    // 使用无参构造器初始化一个Person
    Person p1;
    // 使用有参构造器初始化一个Person
    Person p2("asdasd",121);
    cout << "p2 name的值：" << p2.getName() << endl;

    // 定义一个p3它是p1和p2的和（注意：两个对象可以相加是因为我们重写了运算符重载函数）
    // 注意：这是一个初始化定义的操作，不是一个赋值操作。还有这个初始化有运算符相关操作所以会使用构造器构造，而不会使用拷贝构造器构造
    Person p3 = p1 + p2;
    // 注意：p2在该段代码执行完毕后会立即被销毁掉（原因是p2在后面的代码中没有被使用）
    p2 = p1 + p2;
    cout << "两个对象相加后p3的age=" << p3.getAge() << endl;
    // 注意：这个操作会调用到我们重写的运算符重载函数里面去，而且会使用拷贝构造器构造，因为它是直接初始化加赋值且没有任何运算符相关操作
    Person p4 = p1;

    return EXIT_SUCCESS;
}

/**
 * 实现Person类里面的 getAbs() 函数（注意：实现类里面的某个函数是固定写法，类名 + 两个冒号 + 函数名）
 * const 表示该返回值在函数内部不可以被修改
 */
double Person::getAbs() const {
    return 1.2;
}


/**
 * Student1继承至Person
 */
class Student1: Person {

};
