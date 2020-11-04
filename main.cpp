#include <iostream>
#include "controller/Algorithm.h"
#include "controller/SuffixTableAlgorithm.h"
#include "controller/LCPTableAlgorithm.h"
#include "controller/AlgorithmExecutor.h"
#include "FileExecutor.h"

int main() {
    // Algorithm
    AlgorithmExecutor *algorithmExecutor = new AlgorithmExecutor();
    algorithmExecutor->setAlgorithm(new SuffixTableAlgorithm());
    algorithmExecutor->execute(); // SuffixTableAlgorithm algorithm executed
    algorithmExecutor->setAlgorithm(new LCPTableAlgorithm());
    algorithmExecutor->execute(); // LCPTableAlgorithm algorithm executed

    // File operations
    FileExecutor *fileExecutor = new FileExecutor();
    List<PatternOccurrence> po;
    List<int> occurrences;
    occurrences.add(10); occurrences.add(11);
    po.add(PatternOccurrence("CAT", occurrences));
    std::string path = fileExecutor->createResultFile("C:\\Users\\djnic\\git\\SuffixTableAlgorithm", po);
    std::string text = fileExecutor->loadTextFile("C:\\Users\\djnic\\git\\SuffixTableAlgorithm\\resultFile.txt");
    List<std::string> myList = fileExecutor->loadPatternFile("C:\\Users\\djnic\\git\\SuffixTableAlgorithm\\patternFile.txt");
    std::cout << myList.to_string() << std::endl;
    return 0;
}
