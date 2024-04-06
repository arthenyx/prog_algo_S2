cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)

project(TD04)

# On indique que l'on veut créer un exécutable "ex01" compilé à partir du fichier td02_ex01.cpp
add_executable(ex01 src/ex_01.cpp)

# On indique que l'on veut créer un exécutable "ex02" compilé à partir du fichier td02_ex02.cpp
add_executable(ex02 src/ex_02.cpp)

add_executable(ex03 src/ex_03.cpp)