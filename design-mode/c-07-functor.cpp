//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C++ 仿函数
//============================================================================

#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

/**
 * 比较函数
 * @param a
 * @param b
 * @return
 */
bool mySort(int a,int b) {
    return a < b;
}
// 指定 T 为泛型类型（注意：参数都是引用）
template<class T>
bool mySortT(T const& a,T const& b) {
    return a < b;
}
/**
 * 输出
 * @param a
 */
void display(int a) {
    cout << a << ",";
}
// 指定 T 为泛型类型
template <class T>
void displayT(T const& a) {
    cout << a << ",";
}

/**
 * 防函数的方式实现比较（注意：就是写个类再在里面写个 operator 仿函数，其实就是默认调用operator()函数）
 */
struct SortF {
    bool operator()(int a,int b){
        return a < b;
    }

};
/**
 * 防函数的方式实现输出（注意：就是写个类再在里面写个 operator 仿函数，其实就是默认调用operator()函数）
 */
struct DisplayF {
    void operator()(int a) {
        cout << a << ",";
    }
};

/**
 * 防函数加泛型的方式实现比较（注意：就是写个类再在里面写个 operator 仿函数，其实就是默认调用operator()函数）
 */
template<class T>
struct SortFT {
    bool operator()(T const& a,T const& b) {
        return a < b;
    }
};
/**
 * 防函数加泛型的方式实现输出（注意：就是写个类再在里面写个 operator 仿函数，其实就是默认调用operator()函数）
 */
template<class T>
struct DisplayFT {
    void operator()(T const& a) {
        cout << a << ",";
    }
};

int main() {
    //-------------------普通比较输出--------------------------//
    int arr[] = {1,5,78,0,7};
    /**
     * 排序
     * @param __first 开始位置
     * @param __last  结束位置
     * @param __comp  排序比较函数
     */
    sort(arr,arr+5,mySort);
    /**
     * 循环遍历
     * @param __first 开始位置
     * @param __last  结束位置
     * @param __f     回调函数
     */
    for_each(arr,arr+5,display);
    cout << endl;

    //-------------------泛型比较输出--------------------------//
    int arr1[] = {10,3,565,2,0};
    /**
     * 排序
     */
    sort(arr1,arr1+5,mySortT<int>);
    /**
     * 循环遍历
     */
    for_each(arr1,arr1+5,displayT<int>);
    cout << endl;

    //-------------------仿函数比较输出------------------------//

    int arr2[] = {20,3,45,1,5};
    // 比较
    sort(arr2,arr2+5,SortF());
    // 输出
    for_each(arr2,arr2+5,DisplayF());
    cout << endl;

    //-------------------仿函数加泛型的方式比较输出------------------------//
    int arr3[] = {20,11,52,3,5};
    // 排序
    sort(arr3,arr3+5,SortFT<int>());
    // 遍历输出
    for_each(arr3,arr3+5,DisplayFT<int>());
    return EXIT_SUCCESS;
}

