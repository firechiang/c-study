//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C++ 迭代器相关
//============================================================================

#include <stdio.h>
#include <list>
#include <iostream>

using namespace std;

int main() {

    list<int> ls;
    // 添加元素
    ls.push_back(4);
    ls.push_back(1);
    ls.push_back(10);
    // 不允许修改元素的迭代器
    list<int>::const_iterator it;
    // 迭代数据
    for(it = ls.begin();it != ls.end();it++) {
        cout << *it << endl;
    }
    cout << "------------------------------------------" << endl;
    // 返向迭代器（从右向左开始迭代）
    list<int>::reverse_iterator it2;
    for(it2 = ls.rbegin();it2 != ls.rend();it2++) {
        cout << *it2 << endl;
    }
    return EXIT_SUCCESS;
}

