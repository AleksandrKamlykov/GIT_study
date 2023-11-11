cmake_minimum_required(VERSION 3.26)
project(GIT_study)

set(CMAKE_CXX_STANDARD 14)

add_executable(GIT_study
        main.cpp
        FileManeger.cpp
        FileManeger.h
        includes.h
        FileApp.cpp
        FileApp.h
        Gallows.cpp
        Gallows.h)
