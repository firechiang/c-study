//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C++ 排列组合相关
//============================================================================

#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void swap(char* a,char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * 一个字符数组有几种排列组合的方式
 * 排列组合
 * @param pStr     字符数组
 * @param pPostion 排列组合位置
 */
void Arranged(char* pStr,char* pPostion) {
    // 如果到最后了就直接输出
    if(*pPostion == '\0') {
        cout << pStr << endl;
    }else{
        for(char* pChar=pPostion;*pChar != '\0';pChar++) {
            // 依次和后面的字符交换
            swap(*pChar,*pPostion);
            // 递归再交换
            Arranged(pStr,pPostion + 1);
            // 最后换回来
            swap(*pChar,*pPostion);
        }
    }
}

int main() {
    char str[] = "123";
    // 一个字符数组有几种排列组合的方式
    Arranged(str,str);


    cout << "--------用STL库里面自带的排列组合算法函数（注意：STL库里面的排列组合函数需要保证元素的大小循序，否则会出现数据错误）---------------" << endl;

    do {
        cout << str[0] << str[1] << str[2] << endl;
    } while(next_permutation(str,str+3));
    return EXIT_SUCCESS;
}
