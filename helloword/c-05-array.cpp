//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C++ 数组相关
//============================================================================

#include <stdio.h>
#include <iostream>
#include <string>

int main() {
    // 定义一个数组（注意：数组元素的个数就是数组的长度）
    int array1[] = {0,2,334,454,454};
    // 定义一个长度为5的一个数组，并且前2个位置已有默认值
    int array2[5] = {10,23};
    // 打印数组的内存所在地址
    std::cout << array1 << std::endl;
    // 打印数组第0个位置的值
    std::cout << array2[0] << std::endl;

    //-----------------------------------打印int数组的长度--------------------------------------//
    // sizeof()函数可以返回数组所占的内存，而sizeof(a[0])返回的是数组第一个元素所占的内存，两个相除就得到数组的长度
    int length = sizeof(array1) / sizeof(array1[0]);
    // 定义一个用来装字符串的字符数组
    char buffer[0];
    // 将字符串与数字拼接后放到b变量的内存里面
    sprintf(buffer,"数组array的长度=%d",length);
    // 打印输出b变量内存地址的值（也就是字符串拼接后的结果）
    std:: cout << buffer << std::endl;

    //------------------遍历数组里面的每一个元素----------------------------//
    // sizeof()函数可以返回数组所占的内存，而sizeof(a[0])返回的是数组第一个元素所占的内存，两个相除就得到数组的长度
    int len = sizeof(array1) / sizeof(array1[0]);
    for(int i=0;i<len;i++) {
        std::cout << array1[i] << ",";
    }
    // 打印一个换行（注意：std::endl就是打印一个换行）
    std::cout << "" << std::endl;

    //-----------------数组添加和删除元素------------------------//
    int array3[10] = {10,20,30,10};
    // 指定下表为5的值
    array3[5] = 20;
    // 获取数组的内存地址（注意：这个地址实际上是数组第0个位置的内存地址）
    int *array = array3;
    std::cout << *array << std::endl;
    // 修改数组第5个位置的值（注意：array是第0个位置，加5就表示第5个位置）
    *(array+5) = 22;

    return EXIT_SUCCESS;
}







