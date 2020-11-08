cmake_minimum_required(VERSION 3.17)
project(SuffixTable)

set(CMAKE_CXX_STANDARD 14)

add_executable(SuffixTable main.cpp model/List.cpp model/List.h controller/SuffixTableAlgorithm.cpp controller/SuffixTableAlgorithm.h controller/Algorithm.h model/PTable.cpp model/PTable.h controller/LCPTableAlgorithm.cpp controller/LCPTableAlgorithm.h controller/AlgorithmExecutor.cpp controller/AlgorithmExecutor.h controller/FileExecutor.cpp controller/FileExecutor.h controller/PatternExecutor.cpp controller/PatternExecutor.h model/PatternOccurrence.cpp model/PatternOccurrence.h model/SuffixTable.cpp model/SuffixTable.h model/LCPTable.cpp model/LCPTable.h controller/PatternExecutor.cpp controller/PatternExecutor.h)