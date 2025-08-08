*主要难点还是在高中解析几何忘光光了，抄着网上的公式做的。最痛苦的还是我的点输错了，但我以为代码逻辑有问题。*
# CMake入门
1. 构建最小项目  
在我的项目目录下生成`CMakeLists.txt`
```c
cmake_minimum_required(VERSION 3.15)

# set the project name
project(geometry)

# add the executable
add_executable(geometry main.c mathlib.c)
```
`cmake_minimum_required()`用来指定使用CMake最低版本号，`project`指定项目名称，`add_executable`用来生成可执行文件，第一参数是可执行文件名称，其他是依赖。
2. 构建
为了好看，我们在当前目录下创建一个构建目录build，进入build运行CMake来配置项目
```bash
mkdir build
cd build
cmake -G"MinGW Makefiles" ..
```
3. 编译
   ```bash
   cmake --build .
   ```
   