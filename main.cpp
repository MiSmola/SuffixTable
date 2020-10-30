#include <iostream>
#include "Algorithm.h"
#include "SuffixTable.h"
#include "LCPTable.h"
#include "AlgorithmExecutor.h"
#include "FileExecutor.h"
#include "PatternOccurrence.h"

int main() {
    AlgorithmExecutor *algorithmExecutor = new AlgorithmExecutor();
    algorithmExecutor->setAlgorithm(new SuffixTable());
    algorithmExecutor->execute(); // SuffixTable algorithm executed
    algorithmExecutor->setAlgorithm(new LCPTable());
    algorithmExecutor->execute(); // LCPTable algorithm executed

    //File operations
    FileExecutor *fileExecutor = new FileExecutor();
    PatternOccurrence *patternOccurrence = new PatternOccurrence();
    patternOccurrence->add("CAT", new int[2]{10, 11}, 2);
    std::string path = fileExecutor->createResultFile("C:\\Users\\djnic\\git\\SuffixTable", patternOccurrence);


    return 0;
}
