//============================================================================
// Name        : c++-study.cpp
// Author      : jiang
// Version     :
// Copyright   : Your copyright notice
// Description : C++ 设计模式（适配器模式）
//============================================================================

#include <stdio.h>
#include <iostream>

using namespace std;

/**
 * 适配器目标类（就是最终要调用的类）
 */
struct LeageRctanle {
    private:
        /**
         * 私有成员
         */
        double _x1;
        double _y1;
        double _x2;
        double _y2;
    public:
        /**
         * 构造器
         * @param _x1
         * @param _y1
         * @param _x2
         * @param _y2
         */
        LeageRctanle(double _x1,double _y1,double _x2,double _y2) {
            _x1 = _x1;
            _x2 = _x2;
            _y1 = _y1;
            _y2 = _y2;
        }

        void LeageDraw() {
            cout << "调用LeageDraw()函数：_x1=" << _x1 << ",_x2=" << _x2 << ",_y1=" << _y1 << ",_y2" << _y2 << endl;
        }
};
/**
 * 适配器抽象类
 */
struct Rectanle {
    public:
        /**
         * 行为函数
         * 注意：virtual（表示可重写的），等于0表示该函数没有实现体需要子类重写实现
         **/
        virtual void Draw(string str) = 0;
};

/**
 * 第一种适配器使用多重继承的方式（继承了LeageRctanle和Rectanle）
 * 注意：public 表示父类里面的函数是public的在子类里面还是public
 */
 struct Adaptation1: public LeageRctanle,public Rectanle {
     public:
         /**
          * 构造器
          * @param x
          * @param y
          * @param w
          * @param h
          * 注意：LeageRctanle是调用父类构造器
          */
         Adaptation1(double x, double y, double w, double h) : LeageRctanle(x, y, x+w, y+h) {
             cout << "适配器Adaptation1被创建" << endl;
         }

         /**
          * 重写适适配器抽象类里面的函数
          * 注意：override表示重写
          * @param str
          */
         virtual void Draw(string str) override {
             cout << "适配器Adaptation1.DrawDraw()函数正在调用目标函数,参数str=" << str << endl;
             // 调用父类的LeageDraw()函数
             LeageDraw();
         };

 };

/**
 * 第二种适配器使用组合的方式（就是将目标类作为成员定义，再使用成员调用目标函数）
 * 注意：public 表示父类里面的函数是public的在子类里面还是public
 */
struct Adaptation2: public Rectanle {

    private:
        LeageRctanle _lr;

    public:
        /**
         * 构造器
         * @param x
         * @param y
         * @param w
         * @param h
         * 注意：_lr()是对象创建时初始化_lr成员变量
         */
        Adaptation2(double x, double y, double w, double h):_lr(x, y, x+w, y+h) {
            cout << "适配器Adaptation2被创建" << endl;
        }

    /**
     * 重写适适配器抽象类里面的函数
     * 注意：override表示重写
     * @param str
     */
    virtual void Draw(string str) override {
        cout << "适配器Adaptation2.DrawDraw()函数正在调用目标函数,参数str=" << str << endl;
        // 目标类的LeageDraw()函数
        _lr.LeageDraw();
    };
};

int main() {
    double x=10.3,y=20.2,w=40.1,h=30.0;
    Adaptation1 adapter1(x,y,w,h);
    adapter1.Draw("asdsa");

    Adaptation2 adapter2(x,y,w,h);
    adapter2.Draw("asdsa");
    return EXIT_SUCCESS;
}




