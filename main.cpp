#include <iostream>
#include "Algorithm.h"
#include "SuffixTable.h"
#include "LCPTable.h"
#include "AlgorithmExecutor.h"

int main() {
    AlgorithmExecutor *algorithmExecutor = new AlgorithmExecutor();
    algorithmExecutor->setAlgorithm(new SuffixTable());
    algorithmExecutor->execute(); // SuffixTable algorithm executed
    algorithmExecutor->setAlgorithm(new LCPTable());
    algorithmExecutor->execute(); // LCPTable algorithm executed
    return 0;
}
