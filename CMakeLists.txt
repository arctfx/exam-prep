cmake_minimum_required(VERSION 3.25)
project(exam_prep)

set(CMAKE_CXX_STANDARD 17)

add_executable(exam_prep main.cpp exam2022/Pair.cpp exam2022/Pair.h exam2022/StringPair.cpp exam2022/StringPair.h exam2022/DatePair.cpp exam2022/DatePair.h exam2022/TimePair.cpp exam2022/TimePair.h exam2022/FJSON.h exam2022/DateTimePair.cpp exam2022/DateTimePair.h)
