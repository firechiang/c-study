//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C++ 容器适配器相关
//============================================================================

#include <stdio.h>
#include <iostream>
#include <functional>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // 优先队列（默认最大值在最前面）
    priority_queue<int> pq1;
    // 优先队列（最小值在最前面，greater<int>就是比较逻辑，使得最小值在前面）
    priority_queue<int,vector<int>,greater<int>> pq2;
    // 优先队列（最大值在最前面，less<int>就是比较逻辑，使得最大值在前面）
    priority_queue<int,vector<int>,less<int>> pq3;

    cout << "----------------注意：最大值在前面---------------------------" << endl;
    pq1.push(2);
    pq1.push(10);
    pq1.push(5);
    pq1.push(22);
    while(!pq1.empty()) {
        // 获取头部元素
        int top = pq1.top();
        // 打印数据（注意：最大值在最前面）
        cout << top << ",";
        // 弹出头部元素
        pq1.pop();
    }
    cout << endl;

    cout << "----------------注意：最小值在前面---------------------------" << endl;

    pq2.push(2);
    pq2.push(10);
    pq2.push(5);
    pq2.push(22);
    while(!pq2.empty()) {
        // 获取头部元素
        int top = pq2.top();
        // 打印数据（注意：最大值在最前面）
        cout << top << ",";
        // 弹出头部元素
        pq2.pop();
    }
    cout << endl;

    cout << "----------------注意：最大值在前面---------------------------" << endl;

    pq3.push(2);
    pq3.push(10);
    pq3.push(5);
    pq3.push(22);
    while(!pq3.empty()) {
        // 获取头部元素
        int top = pq3.top();
        // 打印数据（注意：最大值在最前面）
        cout << top << ",";
        // 弹出头部元素
        pq3.pop();
    }
    cout << endl;
    return EXIT_SUCCESS;
}

