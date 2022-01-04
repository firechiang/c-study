# cmake所需要的最小版本
cmake_minimum_required(VERSION 3.17)
# 编译项目名称叫c_study，本号为 1.0
project(c_study VERSION 1.0)

# 设置程序所使用的C++编译器版本
set(CMAKE_CXX_STANDARD 14)
# 是否必须使用上面所指定的C++编译器版本编译程序
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 指定配置文件
# 使用c-study-config.h.in版本配置文件自动生成c-study-config.h版本信息头文件
# 生成的头文件里面其实就是定义了一些静态变量，要使用头文件，在代码里面引入即可
configure_file(c-study-config.h.in c-study-config.h)

INCLUDE_DIRECTORIES(./helloword)

# 程序入口文件
add_executable(c_study design-mode/c-13-thread.cpp)

# 关于多线程的配置，否则使用多线程会报 undefined reference to `pthread_create' 错误
find_package(Threads REQUIRED)
# 添加依赖（注意：c_study就是上面的编译项目名称）
target_link_libraries(c_study Threads::Threads)

# 将指定目录的所有文件添加到编译列表，进行编译（注意：c_study就是上面的编译项目名称，${PROJECT_BINARY_DIR}是要搜索的目录，${PROJECT_BINARY_DIR}就是项目根目录）
# 这里主要是引入c-study-config.h.in版本配置文件
target_include_directories(c_study PUBLIC "${PROJECT_BINARY_DIR}")
# 编译时添加指定选项
#add_compile_options()
# 编译时添加指定命令
#add_definitions(-DFOO -DBAR)

# 编译时变量配置（USE_MAYMATH=ON）（注意：该配置在配置文件里面也配置了，这里是为其赋值）
option(USE_MAYMATH "是否开启使用自己实现的某个核心库" ON)

# 已开启使用自己实现的某个核心库，添加自定义依赖
if (USE_MAYMATH)
    # 添加子模块 MathFunctions（注意：MathFunctions 表示的是目录）
    add_subdirectory(MathFunctions)
    # 创建变量MathFunctions将其加入到EXTRA_LIBS列表
    list(APPEND EXTRA_LIBS MathFunctions)
    # 搜索添加子模块，搜索路劲是 ${PROJECT_BINARY_DIR}/MathFunctions （注意：${PROJECT_BINARY_DIR} 表示项目根目录）
    list(APPEND EXTRA_INCLUDES "${PROJECT_BINARY_DIR}/MathFunctions")
endif ()


