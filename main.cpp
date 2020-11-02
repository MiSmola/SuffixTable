#include <iostream>
#include "Algorithm.h"
#include "SuffixTable.h"
#include "LCPTable.h"
#include "AlgorithmExecutor.h"
#include "FileExecutor.h"

int main() {
    // Algorithm
    AlgorithmExecutor *algorithmExecutor = new AlgorithmExecutor();
    algorithmExecutor->setAlgorithm(new SuffixTable());
    algorithmExecutor->execute(); // SuffixTable algorithm executed
    algorithmExecutor->setAlgorithm(new LCPTable());
    algorithmExecutor->execute(); // LCPTable algorithm executed

    // File operations
    FileExecutor *fileExecutor = new FileExecutor();
    List<PatternOccurrence> po;
    List<int> occurrences;
    occurrences.add(10); occurrences.add(11);
    po.add(PatternOccurrence("CAT", occurrences));
    std::string path = fileExecutor->createResultFile("C:\\Users\\djnic\\git\\SuffixTable", po);
    std::string text = fileExecutor->loadTextFile("C:\\Users\\djnic\\git\\SuffixTable\\resultFile.txt");
    List<std::string> myList = fileExecutor->loadPatternFile("C:\\Users\\djnic\\git\\SuffixTable\\patternFile.txt");
    std::cout << myList.to_string() << std::endl;
    return 0;
}
