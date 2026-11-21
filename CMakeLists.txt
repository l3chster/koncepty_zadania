cmake_minimum_required(VERSION 3.16)
project(KonceptyZadania LANGUAGES CXX)

foreach(n RANGE 1 5)
    add_subdirectory(zadanie${n})
endforeach()
