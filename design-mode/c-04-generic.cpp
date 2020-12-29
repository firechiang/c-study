//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C++ 设计模式（泛型使用）
//============================================================================

#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;


/**
 * 比较大小并返回大的值
 * @tparam T
 * @param a
 * @param b
 * @return
 */
// 这一行指定T是泛型类型
template <class T>
T maxx(T a,T b) {
    return a > b ? a : b;
}
// 特列（就是maxx()函数针对特定类型进行重载实现，也就是如果调用maxx()函数传入的参数是char*类型就会调用到这个实现）
template<>
char* maxx(char* a,char* b) {
    // 比较字符串的大小
    return strcmp(a,b) > 0 ? a : b;
}

// 指定T1和T2是泛型
template<class T1,class T2>
int minn(T1 a,T2 b) {
    // 将a或b强制转换成int类型
    return static_cast<int>(a > b ? a : b);
}

// 1+2+3+...
template<int n>
struct Sum {
    enum Value {
        // Sum(n) = Sum(n-1) + n。如果n=3就是，N = （3 -1） + （2-1） + 3
        // n-1相当于泛型传参的过程，只要n-1不等于0就会一直调用，加入n=3调用过程如下：
        // 第一次： 3 -1 = 2 = N1
        // 第二次： 2 -1 = 1 = N2
        // 第三次：因为 N 到 1 了所以就到最后一步了，最终结果是：N1(2) + N2(1) + n(3) = 6
        N = Sum<n-1>::N+n
    };
};
// 特列（就是n=1，就直接让N=1）
template<>
struct Sum<1> {
    enum Value {
        N = 1
    };
};

int main() {
    int a = 10,b = 20;
    int val = maxx(a,b);
    cout << "a和b数值大的是：" << val << endl;
    // Sum<10> 表示n=10，::N表示取N的值
    cout << "3累加的和=" << Sum<3>::N << endl;
    return EXIT_SUCCESS;
}

