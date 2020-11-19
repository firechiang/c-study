//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C++ 动态数组相关
//============================================================================

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 定义一个动态数组(注意：动态数组的初始容量是6)
    std::vector<int> v1 = {12,45,20};
    // 在数组尾部添加一个元素
    v1.push_back(10);
    // 在尾部的前一个位置插入元素1（注意：v1.end()就是获取最后一个有数据的位置，--就得到前一个位置）
    v1.insert(--v1.end(),1);
    // 在倒数第4个位置插入元素23（注意：v1.end()-3就是到数第4个位置，从0个位置开始数）
    v1.insert(v1.end()-3,23);
    // 删除最后一个元素
    //v1.pop_back();
    // 删除倒数第2个元素
    //v1.erase(v1.end()-1);
    // 打印动态数组的容量
    std::cout << v1.capacity() << std:: endl;
    // 打印动态数组的已经装有元素的个数（其实就是数组的大小）
    std::cout << v1.size() << std::endl;
    // 遍历动态数组
    for (int i = 0; i < v1.size(); ++i) {
        std::cout << v1[i] << ",";
    }
    // 打印一个换行
    std::cout << "" << std::endl;
    return EXIT_SUCCESS;
}

