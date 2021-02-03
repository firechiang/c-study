//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C++ map简单使用
//============================================================================

#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct Display {
    // 重载()号运算符
    void operator()(pair<string,double> info) {
        cout << "key=" << info.first << ",value=" << info.second << endl;
    }
};

int main() {
    // 定义一个map
    map<string,double> smap;
    // map添加一个元素
    smap["a"] = 20.8;
    /**
     * 使用insert函数给map添加元素（注意：pair也是一个数据对象）
     * 注意：insert()函数插入元素，如果元素已存在，就不会插入了，也你不会修改
     */
    smap.insert(pair<string,double>("b",30.54));
    /**
     * 使用insert函数给map添加元素（注意：map<string,double>::value_type也是一个数据对象）
     * 注意：insert()函数插入元素，如果元素已存在，就不会插入了，也你不会修改
     */
    smap.insert(map<string,double>::value_type("c",63.10));
    // 删除元素（返回被删除的元素）
    //smap.erase("c");
    // 删除所有元素（注意：这个其实是通过范围删除）
    //smap.erase(smap.begin(),smap.end());
    /**
     * for_each遍历map
     * @param __first 开始位置
     * @param __last  结束位置
     * @param fn      遍历结果处理函数（注意：Display() 可以成为处理函数是因为我们重写了Display的括号重载运算符）
     */
    for_each(smap.begin(),smap.end(),Display());
    // 查找map里面的一对元素(注意：这个find()函数返回的是一对元素的迭代器)
    map<string,double>::iterator it = smap.find("a");
    // 如果找到了数据
    if(it != smap.end()) {
        cout << "it的key=" << (it->first) << endl;
    }

    map<string,double>::iterator ii;
    ii = smap.begin();
    // 再循环内删除元素
    while(ii != smap.end()) {
        cout << "二次遍历，key=" << (ii->first) << ",value=" << (ii->second) << endl;
        if(ii->first == "c") {
            // 删除元素（注意：++一定要写否则无法遍历到下一个元素（因为指针没有移动，永远指向当前元素，当然也不会等于smap.end()），会陷入死循环）
            // 注意：删除了就不能再++了，所以要先赋值再++（函数是++后才执行的，且参数是++之前的值）
            smap.erase(ii++);
        }else{
            // 注意：++一定要写否则无法遍历到下一个元素（因为指针没有移动，永远指向当前元素，当然也不会等于smap.end()），会陷入死循环
            ii++;
        }
    }
    cout << endl;
    // 再循环内删除元素
    for(map<string,double>::iterator iii = smap.begin();iii != smap.end();iii++) {
        cout << "三次遍历，key=" << (iii->first) << ",value=" << (iii->second) << endl;
        if(iii->first == "a") {
            // 删除元素（注意：元素删除后就失效了，将返回值值，赋给它，就是让当前 iii不失效）
            iii = smap.erase(iii);
        }
    }
    cout << "三次遍历完成" << endl;
    return EXIT_SUCCESS;
}

