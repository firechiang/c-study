//
// Created by chiangfire on 2022/1/4.
// 子模块实际实现代码
//
#include <iostream>
#include "MathFunctions.h"

double mysqrt(double x) {
    if(x <= 0) {
        return 0;
    }
    double result = x;
    for(int i=0;i<10;i++) {
        if(result <= 0) {
            return 0.1;
        }
        double delta = x - (result * result);
        result = result + 0.5 * delta / result;
        std::cout << "Computing sqrt of" << x << " to be" << result << std::endl;
    }
    return result;
}
