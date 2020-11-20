//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C/C++ 字符串相关
// 注意：
// 1，字符串最后一个字符是 \0，也就是如果定义一个字符串指定了长度，那么它实际的字符个数是要比长度少一个的，因为最后一个是默认的\0
// 2，char[] 和 char× 定义的变量的区别。char[]可变长度，char* 如果指向常量区是不可变的（就是写死字符串的值），如果指向的是可变数组，那么它的值是可变的
//============================================================================

#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

// 定义一个指针变量，字符数组常量，也就是一个字符串常量（注意：char*不可变长度）
char* I_STR = "我是常量";

int main() {
    cout << "测试打印" << endl;
    // 字符串最后一个字符是 \0，也就是如果定义一个字符串指定了长度，那么它实际的字符个数是要比长度少一个的，因为最后一个是默认的\0
    // 注意：创建字符串不推荐指定长度，直接不写长度就可以了，比如：char strHelloword[] = "sadasdas";
    // 注意：这是C语言定义字符串的方式
    char strHelloword[10] = "sdsdsdsss";
    // 创建一个指针变量，它是一个字符数组（内存里面有一块区域存储了字符数组的值，我们×str指针指向它）（注意：这是C语言定义字符串的方式）
    char* str = "sdsdfsdfsdfsd";
    cout << str << endl;
    // 打印指针str的内存地址
    cout << &str << endl;
    // 计算字符串长度
    int length  = sizeof(str) / sizeof(str[0]);
    for (int i = 0; i < length; ++i) {
        cout << str[i] << ",";
    }
    cout << "最后输出一个换行" << endl;
    // 获取字符串长度
    int len = strlen(str);
    cout << len << endl;
    // 比较两个字符串是否相等（相等返回0）
    int eq = strcmp(strHelloword,strHelloword);
    cout << eq << endl;
    // 注意：这是C语言定义字符串的方式
    char a[20] = "sdfdsfdsf";
    char b[10] = "AAA";
    // 将字符串b的前2个字符拷贝到字符串a的前面（注意：有个等价安全的函数 strncpy_s）
    // 注意：如果a空间不够，拷贝过来会报错
    strncpy(a,b,2);
    // 注意：这是C语言定义字符串的方式
    char fff[20] = "asdas";
    char ggg[5] = "DDDD";
    // 将字符串ggg拷贝到字符串字符串fff（注意：有个等价安全的函数 strcpy_s）
    strcpy(fff,ggg);
    cout << a << endl;
    //（注意：有个等价安全的函数 strlen_s）
    int jleng = strlen(fff);
    for (int j = 0; j < jleng; ++j) {
        cout << fff[j] << ",";
    }
    cout << "输出一个换行" << endl;
    char aa[] = "asdasddas10";
    char bb[] = "VVV";
    // 字符串拼接（将字符串bb拼接到字符串aa后面）（注意：有个等价安全的函数 strcat_s）
    strcat(aa,bb);
    cout << aa << endl;

    // 在字符串aa里面查找第一次出现s字符的位置
    char *cc = strchr(aa,'s');
    cout << cc << endl;
    // 在字符串aa里面查找第一次出现da字符串的位置
    strstr(aa,"da");

    // C++语言的方式定义一个字符串
    string astr = "我的长度=";
    //  C++语言的方式定义一个字符串（使用构造器初始化）
    string s = string("asdasdasd");
    // 打印字符串的长度（注意：它还有一个size()函数和length()函数等价）
    cout << astr.length() << endl;
    // 打印字符串的内存大小
    cout << astr.capacity() << endl;
    // C++风格的字符串拼接（其实就是直接使用+号）
    cout << astr + s << endl;
    return EXIT_SUCCESS;
}

