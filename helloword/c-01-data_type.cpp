//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C++ 数据类型
//============================================================================
/**
 * char	              1 个字节	    -128 到 127 或者 0 到 255
 * unsigned char      1 个字节	    0 到 255
 * signed char	      1 个字节	    -128 到 127
 * int	              4 个字节	    -2147483648 到 2147483647
 * unsigned int	      4 个字节	    0 到 4294967295
 * signed int	      4 个字节	    -2147483648 到 2147483647
 * short int	      2 个字节	    -32768 到 32767
 * unsigned short int 2 个字节	    0 到 65,535
 * signed short int	  2 个字节	    -32768 到 32767
 * long int	          8 个字节	    -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807
 * signed long int	  8 个字节	    -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807
 * unsigned long int  8 个字节	    0 到 18,446,744,073,709,551,615
 * float	          4 个字节	          精度型占4个字节（32位）内存空间，+/- 3.4e +/- 38 (~7 个数字)
 * double	          8 个字节	          双精度型占8 个字节（64位）内存空间，+/- 1.7e +/- 308 (~15 个数字)
 * long double	      16 个字节	          长双精度型 16 个字节（128位）内存空间，可提供18-19位有效数字。
 * wchar_t	          2 或 4 个字节	1 个宽字符
 */
#include <stdio.h>
#include <stdlib.h>

// 声名test函数
void test();

/*int main() {
	test();
	return EXIT_SUCCESS;
}*/

// 实现test()函数
void test() {
	printf("我是第一个测试程序,我的名字是：%s\n","jiang");
	// 占1 个字节	-128 到 127 或者 0 到 255
	char a[10] = "a";
	// 占2 个字节	-32768 到 32767
	short int s = 97;
	// 占4 个字节	-2147483648 到 2147483647
	int m = 10;
	long int n = 99;
	float f = 66.1;
	double d = 66.01;
	long double fd = 99.21;
	bool is = true;
	// 大写字母L告诉编译器为"d"字分配两个字节的空间（注意：该数据类型一定要加L）
    wchar_t wt[] = L"d";
    long long ll = 10;
    printf("a=%s,s=%d,m=%d,n=%d,f=%f,d=%f,fd=%f,is=%d,wt=%s,ll=%d",a,s,m,n,f,d,fd,is,wt,ll);
}
