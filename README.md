#### 一、[下载 Windows GCC编译工具包（注意：/c-study/utils文件夹里面也有）](https://sourceforge.net/projects/mingw-w64/files/mingw-w64/mingw-w64-release/)
![image](https://github.com/firechiang/c-study/blob/master/images/download_gcc.png)

#### 二、基础相关说明
 - .h文件是头文件就是用来定义函数的定义的（一般我们是将.h文件引入到.cpp里面来，然后实现里面的函数定义）
 - 有符号的数值都是使用二进制的首位作为符号标识（0 表示正数，1 表示负数）
 - 32位的机器一次可以处理4个字节的数据（一个字节占8位）
 - 大小端表示说明（大端：二进制是正序排列存储，小端：二进制是倒序排列存储）
 - unsigned 表示无符号
 - 标准库里面后面带_s的函数表示是安全内存函数，不容易出现错误
 - &符号是取内存地址，如果是函数的参数则表示为引用;*是取内存地址里面的数据，如果是函数的参数则表示为指针
 - const关键字表示不可变（如果有多个const以和变量名最近的那个const为基准），被它修饰的是不可修改的(注意：const修饰规则（就是优先级）是先修饰const左边部分，如果左边没有，就是修饰const右边部分)
 - 使用new关键字分配的内存用delete关键字释放（适用于C++），使用malloc()函数分配的内存用free()函数释放（适用于C）（注意：linux查看默认栈大小使用 ulimit -s 命令）
 - auto关键字是自动推倒类型就像java11的var一样
 
#### 三、开发注意事项
 - 指针定义好后建议立即初始化并指向正确的数据(注意:如果没有数据可以指向建议初始化成NULL（就是：int* a = NULL）)
 - 指针内存被释放（释放内存使用delete或free）以后或者不用了建议将指针至为空（a = NULL）