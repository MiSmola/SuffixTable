#include <iostream>
#include "controller/Algorithm.h"
#include "controller/SuffixTableAlgorithm.h"
#include "controller/LCPTableAlgorithm.h"
#include "controller/AlgorithmExecutor.h"
#include "FileExecutor.h"
#include "model/SuffixTable.h"

int main() {
    // Mock data preparation
    std::string inputText;
    std::cout << "Insert word: ";
    std::cin >> inputText;

    // Algorithm
    AlgorithmExecutor *algorithmExecutor = new AlgorithmExecutor();
    algorithmExecutor->setAlgorithm(new LCPTableAlgorithm());
    algorithmExecutor->execute();
    algorithmExecutor->setAlgorithm(new SuffixTableAlgorithm(inputText));
    std::cout << static_cast<SuffixTable *>(algorithmExecutor->execute())->to_string() << std::endl;

    // File operations
    FileExecutor *fileExecutor = new FileExecutor();
    List<PatternOccurrence> po;
    List<int> occurrences;
    occurrences.add(10);
    occurrences.add(11);
    po.add(PatternOccurrence("CAT", occurrences));
    std::string path = fileExecutor->createResultFile("C:\\Users\\djnic\\git\\SuffixTableAlgorithm", po);
    std::string text = fileExecutor->loadTextFile("C:\\Users\\djnic\\git\\SuffixTableAlgorithm\\resultFile.txt");
    List<std::string> myList = fileExecutor->loadPatternFile(
            "C:\\Users\\djnic\\git\\SuffixTableAlgorithm\\patternFile.txt");
    std::cout << myList.to_string() << std::endl;

    return 0;
}
