cmake_minimum_required(VERSION 3.17)
project(SuffixTable)

set(CMAKE_CXX_STANDARD 14)

add_executable(SuffixTable main.cpp SuffixTable.cpp SuffixTable.h Algorithm.h PTable.cpp PTable.h LCPTable.cpp LCPTable.h AlgorithmExecutor.cpp AlgorithmExecutor.h FileExecutor.cpp FileExecutor.h PatternExecutor.cpp PatternExecutor.h PatternOccurrence.cpp PatternOccurrence.h)