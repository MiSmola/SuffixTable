cmake_minimum_required(VERSION 3.17)
project(SuffixTable)

set(CMAKE_CXX_STANDARD 14)

add_executable(SuffixTable main.cpp model/datastructures/List.cpp model/datastructures/List.h model/SuffixTableAlgorithm.cpp model/SuffixTableAlgorithm.h model/Algorithm.h model/datastructures/PTable.cpp model/datastructures/PTable.h model/LCPTableAlgorithm.cpp model/LCPTableAlgorithm.h model/AlgorithmExecutor.cpp model/AlgorithmExecutor.h model/FileExecutor.cpp model/FileExecutor.h model/PatternExecutor.cpp model/PatternExecutor.h model/datastructures/PatternOccurrence.cpp model/datastructures/PatternOccurrence.h model/datastructures/SuffixTable.cpp model/datastructures/SuffixTable.h model/datastructures/LCPTable.cpp model/datastructures/LCPTable.h model/PatternExecutor.cpp model/PatternExecutor.h controller/Controller.cpp controller/Controller.h controller/Constants.h)