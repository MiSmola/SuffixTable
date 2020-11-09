#include <iostream>
#include "controller/Algorithm.h"
#include "controller/SuffixTableAlgorithm.h"
#include "controller/LCPTableAlgorithm.h"
#include "controller/AlgorithmExecutor.h"
#include "controller/FileExecutor.h"
#include "model/SuffixTable.h"
#include "controller/PatternExecutor.h"

int main() {
    // Mock data preparation
//    std::string inputText;
//    std::cout << "Insert word: ";
//    std::cin >> inputText;

    // Algorithm
//    AlgorithmExecutor *algorithmExecutor = new AlgorithmExecutor();
//    algorithmExecutor->setAlgorithm(new LCPTableAlgorithm());
//    algorithmExecutor->execute();
//    algorithmExecutor->setAlgorithm(new SuffixTableAlgorithm(inputText));
//    std::cout << static_cast<SuffixTable *>(algorithmExecutor->execute())->to_string() << std::endl;

    // File operations
//    FileExecutor *fileExecutor = new FileExecutor();
//    List<PatternOccurrence> po;     //load to list instead of mocking(?)
//    List<int> occurrences;
//    occurrences.add(10);
//    occurrences.add(11);
//    po.add(PatternOccurrence("CAT", occurrences));
//    std::string path = fileExecutor->createResultFile("C:\\Users\\djnic\\git\\SuffixTable", po);
//    std::string text = fileExecutor->loadTextFile("C:\\Users\\djnic\\git\\SuffixTable\\resultFile.txt");
//    List<std::string> myList = fileExecutor->loadPatternFile(
//            "C:\\Users\\djnic\\git\\SuffixTable\\testFiles\\patternFile-camel.txt");
//    std::cout << myList.to_string() << std::endl;

    // Pattern operations
    FileExecutor *fileExecutor = new FileExecutor();
    PatternExecutor *patternExecutor = new PatternExecutor(fileExecutor,
                                                           "C:\\Users\\djnic\\git\\SuffixTable\\testFiles",
                                                           "C:\\Users\\djnic\\git\\SuffixTable\\testFiles\\patternFile-camel.txt",
                                                           "C:\\Users\\djnic\\git\\SuffixTable\\testFiles\\textFile-camel.txt");
    AlgorithmExecutor *algorithmExecutor = new AlgorithmExecutor();
    algorithmExecutor->setAlgorithm(new SuffixTableAlgorithm(
            fileExecutor->loadTextFile("C:\\Users\\djnic\\git\\SuffixTable\\testFiles\\textFile-camel.txt")));
    patternExecutor->findAll(algorithmExecutor->execute());

    return 0;
}
