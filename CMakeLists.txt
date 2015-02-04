cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project("Polynomial regression of order 2" C)


add_executable(poly2 test.c poly2reg.c)