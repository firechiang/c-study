# 将 mysqrt.cpp 文件里面的代码打成子模块，名字叫 MathFunctions，并引入
# 当前目录里面代码是子模块示例
add_library(MathFunctions mysqrt.cpp MathFunctions.h)