//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C/C++ 类型转换相关
//============================================================================

#include <stdio.h>
#include <iostream>

/**
 * 定义一个类
 */
struct Animal {

};

/**
 * 定义一个类继承至Animal
 */
struct Dog: public Animal {

};

int main() {
    int eee = 1;
    // 将eee强制转换为double类型
    double eee1 = (double)eee;
    // 将1强制转换为double类型
    double eee2 = double(1);
    // 不可变的int变量
    int const ssss = 1;
    // 定义ssss1指针变量指向ssss变量（注意：因为ssss不可变所以需要使用const_cast转换来获取ssss的可变指针）
    int* ssss1 = const_cast<int*>(&ssss);
    int aaaaaa = 1;
    // 将aaaaaa内存地址里面的数据转换为int类型（注意：这种转换要求转换前后的类型所占用的内存大小一致）
    int* aaaaaa1 = reinterpret_cast<int*>(&aaaaaa);

    int fff = 1;
    // 使用static_cast将int类型转换为double（注意：static_cast用于基础数据类型转换，和有继承关系的类对象和类指针之间的转换（可能会丢失精度），它不会产生动态转换的类型安全检查的开销，因为它不做类型检查，完全交给程序员）
    double fff1 = static_cast<double>(fff);

    Dog dog;
    // 将dog转换为Animal类型（注意：dynamic_cast用于在多态体系中的类型转换(就是有继承关系和虚函数的类)，用于类层次间的向上和向下转换，向下转换时对于不能转换的返回NULL）
    Animal* animal = dynamic_cast<Animal*>(&dog);
    return EXIT_SUCCESS;
}

