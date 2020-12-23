//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C/C++ IO流相关
//============================================================================

#include <stdio.h>
#include <limits>
#include <iostream>
#include <fstream>

using namespace std;

// 测试
void test1();
// 边读边写
void readAndWrite();

int main() {
    //test1();
    // 边读边写
    readAndWrite();
    return EXIT_SUCCESS;
}

// 边读边写
void readAndWrite() {
    /**
     * 以二进制的方式打开源文件（注意：以下的代码就相当于 ifstream in = new ifstream（））
     * ios::in        打开文件进行读操作（ifstream默认模式）
     * ios::out       打开文件进行写操作，如果文件不存在则创建文件（ofstrteam默认模式）
     * ios::ate       打开一个已有输入或输出文件并查找到文件尾
     * ios::app       打开文件以便在文件的尾部添加数据
     * ios::nocreate  打开文件，如果文件不存在则打开失败
     * ios::trunc     打开文件，如果文件存在，则清空文件原有内容
     * ios::binary    以二进制方式打开文件
     */
    ifstream in("/home/chiangfire/data-test/file.txt",ios::binary);
    // 打开成功
    if(!in.fail()) {
        // 打开目标文件
        ofstream out("/home/chiangfire/data-test/file1.txt",ios::trunc);
        int bufferSize = 1024;
        // 用于存储读取的信息
        char buffer[bufferSize];
        // 如果还没有读到最后
        while(!in.eof()){
            /**
             * buffer 用于存储读取数据的数组
             * size   最大读取的字节数（小于等于用于存储读取数据的数组的长度）
             */
            in.read(buffer,bufferSize);
            // 实际读取的数据长度
            streamsize count = in.gcount();
            // 将数据写入到文件
            out.write(buffer,count);
        }

        // 关闭目标文件
        out.close();
        // 关闭源文件
        in.close();
    }
}

void test1() {
    fstream fout;
    /**
     * 打开一个文件的输出流（注意：如果文件不存在，则不会打开，但也不会报错）
     * ios::in        打开文件进行读操作（ifstream默认模式）
     * ios::out       打开文件进行写操作，如果文件不存在则创建文件（ofstrteam默认模式）
     * ios::ate       打开一个已有输入或输出文件并查找到文件尾
     * ios::app       打开文件以便在文件的尾部添加数据
     * ios::nocreate  打开文件，如果文件不存在则打开失败
     * ios::trunc     打开文件，如果文件存在，则清空文件原有内容
     * ios::binary    以二进制方式打开文件
     */
    fout.open("/home/chiangfire/data-test/file.txt",ios::out);
    // 这个写法和上面的写法一致（打开一个文件的输出流，变量的名字叫fout）
    //fstream fout("/home/chiangfire/data-test/file.txt");
    if(fout.fail()) {
        cout << "打开文件失败" << endl;
    }
    int a,index=0;
    // cin >> a 从控制台获取输入赋值给a变量（只要不为空就会继续循环）
    while(cin >> a) {
        cout << "a=" << a << endl;
        // 将输入数据写入file1文件
        fout << 'a=' << a << endl;
        index++;
        if(index == 2) {
            break;
        }
    }
    // 清空缓冲区里面的所有数据
    //cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
    // 清空缓冲区的一格数据
    cin.ignore();
    char s;
    cin >> s;
    cout << "s=" << s << endl;
    // 关闭输出流
    fout.close();
}



