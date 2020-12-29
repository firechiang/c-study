//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C++ 容器集合简单使用
//============================================================================

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>

using namespace std;

struct Display {
    // 重载()号运算符
    void operator()(int i) {
        cout << i << endl;
    }
};

int main() {
    int iArr[] = {1,20,10,30};
    /**
     * 使用数组创建 Vector（相当于JAVA 的 ArrayList）,最后一个参数是取几个数据放到集合
     * @param __first 数组
     * @param __last  最大长度
     */
    vector<int> iVector(iArr,iArr + 4);
    /**
     * 使用数组创建 list（相当于JAVA 的 LinkedList）,最后一个参数是取几个数据放到集合
     * @param __first 数组
     * @param __last  最大长度
     */
    list<int> ls(iArr,iArr + 4);
    /**
     * 使用数组创建 deque（相当于JAVA 的 队列）,最后一个参数是取几个数据放到集合
     * @param __first 数组
     * @param __last  最大长度
     */
    deque<int> qu(iArr,iArr + 4);
    // 初始化一个队列（先进先出）
    queue<int> iQueue(qu);
    // 初始化一个栈（先进后出）
    stack<int> iStack(qu);
    // 优先队列，按优先权
    priority_queue<int> pq(iArr,iArr+4);
    // 迭代遍历集合
    auto it = iVector.begin();
    for(;it != iVector.end();it++) {
        cout << *it << ",";
    }
    // 输出一个换行
    cout << endl;
    /**
     * for_each遍历集合（）
     * @param __first 开始位置
     * @param __last  结束位置
     * @param fn      遍历结果处理函数（注意：Display() 可以成为处理函数是因为我们重写了Display的括号重载运算符）
     */
    for_each(ls.begin(),ls.end(),Display());
    // 循环队列(队列不为空就一直循环)
    while (!iQueue.empty()) {
        // 取出一个元素并打印（注意：front()函数不会移除元素）
        cout << iQueue.front() << ",";
        // 移除一个元素
        iQueue.pop();
    }
    cout << endl;
    return EXIT_SUCCESS;
}

