//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C/C++ auto_ptr智能指针相关（注意：这个在C++ 17的标准中已经被废弃删除了，所以这个不推荐使用了）
//============================================================================

#include <stdio.h>
#include <iostream>
#include <memory>
#include <string.h>
#include <string>

using namespace std;

/**
 * auto_ptr智能指针的范围（注意：出了这个大括号 auto_ptr 指针自动销毁掉，当然所指向的内存也会自动销毁）
 * auto_ptr指针被销毁时它所指向的对象会被自动销毁掉。还有两个auto_ptr指针不能指向同一个对象，否则只有后面那个指针有效，前面那个指针将指向一个 nullptr（空）（注意：这个在C++ 17的标准中已经被废弃删除了，所以这个不推荐使用了）
 * @return
 */
int main() {
    //shared_ptr
    //weak_ptr

    // auto_ptr智能指针的范围（注意：出了这个大括号 auto_ptr 指针自动销毁掉，当然所指向的内存也会自动销毁）
    // auto_ptr指针被销毁时它所指向的对象会被自动销毁掉。还有两个auto_ptr指针不能指向同一个对象，否则只有后面那个指针有效，前面那个指针将指向一个 nullptr（空）（注意：这个在C++ 17的标准中已经被废弃删除了，所以这个不推荐使用了）
    {
        // 申明一个auto_ptr指针变量名字叫p1，它所指向的是一个int类型的数据
        auto_ptr<int> p1(new int(10));

        // 申明一个auto_ptr指针变量名字叫laun，它所指向的是一个string指针类型的数组
        auto_ptr<string> laun[2] = {
                auto_ptr<string>(new string("sdfsdfsd")),
                auto_ptr<string>(new string("fgfdgfdgdf"))
        };
        // 判断智能指针不为空（注意：这个是智能指针的判断方式，如果是平常的指针就是使用 != NULL）
        if(&p1 != nullptr) {
            cout << *p1 << endl;
        }
        cout << *laun[0] << endl;
        // 申明一个智能指针名字叫laun2，所指向的是laun指针所指向对象的第一个元素（就是指向laun[0]所指向的对象）
        auto_ptr<string> laun2 = laun[0];
        cout << "asdsadas=" << *laun2 << endl;
        // 注意：这个不会打印，不会执行，因为报错了。原因：laun[0]指针所指向对象的所有权在上面已经发生了改变（两个auto_ptr指针不能指向同一个对象，否则只有后面那个指针有效，前面那个指针将指向一个 nullptr（空））
        //cout << "有数据：" << *laun[0] << endl;
    }
    return EXIT_SUCCESS;
}
