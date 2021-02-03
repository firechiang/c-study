//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C++ STL algorithm（算法）工具相关（包含匿名函数和lambda表达式）
//============================================================================

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    char b = ',';
    int array1[] = {1,2,3,4,5};
    int array2[] = {10,20,30,40,50};
    int res[5];

    /**
     * 转换数据
     * @param __first1 第一个集合开始位置
     * @param __last1  第一个集合的结束位置
     * @param __first2 第二个集合（注意：第一个集合第二个容器的长度要相同）
     * @param __result 转换后的集合（注意：转换后的集合要和第一个，第二个容器的长度要相同）
     * @param __binary_op 转换逻辑（就是转换回调函数）。注意：plus<int>()函数是将两个集合中位置相同的数值相加
     */
    transform(array1,array1+5,array2,res,plus<int>());

    /**
     * 匿名函数或lambda表达式的方式循环遍历
     * 注意：[] 里面写全局参数，() 里面写回调函数的参数，void 表示返回值类型（注意：void标识没有返回值）
     */
    for_each(res,res+5,[b](int a) -> void {
        cout << a << b;
    });
    cout << endl;

    int arr1[] = {1,20,60,3,1,2,1,4,1,4,5,5,7,7,};
    /**
     * 查找数组某个元素出现的次数（注意：这里是查找7出现的次数）
     * @param __first 数组的开始位置
     * @param __last  数组的结束位置（注意：这个是我们算出来的，不是写死的）
     * @param __value 要计算的元素
     */
    int cou1 = count(arr1,arr1+sizeof(arr1)/sizeof(arr1[0]),7);
    cout << "7出现了" << cou1 << "次" << endl;

    /**
     * 根据自己的逻辑查找某些元素出现的次数（注意：这里是查找是小于7出现的次数）
     * @param __first 数组的开始位置
     * @param __last  数组的结束位置（注意：这个是我们算出来的，不是写死的）
     * @param __pred  逻辑回调函数（注意：less<int>()是比较函数，7 是放在比较右边边的所以是要小于）
     */
    int cou2 = count_if(arr1,arr1+sizeof(arr1)/sizeof(arr1[0]),bind2nd(less<int>(),7));
    cout << "小于7的出现了" << cou2 << "次" << endl;


    /**
     * 根据自己的逻辑查找某些元素出现的次数（注意：这里是查找是大于7出现的次数）
     * @param __first 数组的开始位置
     * @param __last  数组的结束位置（注意：这个是我们算出来的，不是写死的）
     * @param __pred  逻辑回调函数（注意：less<int>()是比较函数，7 是放在比较左边的所以是要大于）
     */
    int cou3 = count_if(arr1,arr1+sizeof(arr1)/sizeof(arr1[0]),bind1st(less<int>(),7));
    cout << "大于7的出现了" << cou3 << "次" << endl;

    int len = sizeof(arr1) / sizeof(arr1[0]);
    /**
     * 二分查找某个元素是否存在（注意：二分查找原理是 先排序，再从中间切开，比较第二段的第一个元素，是否比要查找的元素大，如果大就从第二段开始查找）
     * 注意：这里是查 7 是否在数组里面存在
     */
    int boolean = binary_search(arr1,arr1 + len,7);
    cout << "7在数组arr1里面是否存在：" << boolean << endl;

    // 将arr1数组里面的第二个位置到第6个重新生一个新的数组
    vector<int> iA(arr1+2,arr1+3);
    /**
     * search()函数是查找某段数组在原数组中出现的位置
     */
    cout << *search(arr1,arr1+len,iA.begin(),iA.end()) << endl;
    return EXIT_SUCCESS;
}
