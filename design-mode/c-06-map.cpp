//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C++ map简单使用
//============================================================================

#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct Display {
    // 重载()号运算符
    void operator()(pair<string,double> info) {
        cout << "key=" << info.first << ",value=" << info.second << endl;
    }
};

int main() {
    // 定义一个map
    map<string,double> smap;
    // map添加一个元素
    smap["a"] = 20.8;
    // 使用insert函数给map添加元素（注意：pair也是一个数据对象）
    smap.insert(pair<string,double>("b",30.54));
    // 使用insert函数给map添加元素（注意：map<string,double>::value_type也是一个数据对象）
    smap.insert(map<string,double>::value_type("c",63.10));
    /**
     * for_each遍历map
     * @param __first 开始位置
     * @param __last  结束位置
     * @param fn      遍历结果处理函数（注意：Display() 可以成为处理函数是因为我们重写了Display的括号重载运算符）
     */
    for_each(smap.begin(),smap.end(),Display());
    // 查找map里面的一对元素(注意：这个find()函数返回的是一对元素的迭代器)
    map<string,double>::iterator it = smap.find("a");
    // 如果找到了数据
    if(it != smap.end()) {
        cout << "it的key=" << (it->first) << endl;
    }
    return EXIT_SUCCESS;
}

