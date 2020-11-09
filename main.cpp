#include <iostream>
#include "model/Algorithm.h"
#include "model/SuffixTableAlgorithm.h"
#include "model/LCPTableAlgorithm.h"
#include "model/AlgorithmExecutor.h"
#include "model/FileExecutor.h"
#include "model/datastructures/SuffixTable.h"
#include "model/PatternExecutor.h"
#include "controller/Controller.h"

#include <thread>
#include <chrono>

#define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PBWIDTH 60

void printProgress(double percentage) {
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    int val = (int) (percentage * 100);
    int lpad = (int) (percentage * PBWIDTH);
    int rpad = PBWIDTH - lpad;
    printf("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
    fflush(stdout);
}

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
//    FileExecutor *fileExecutor = new FileExecutor();
//    PatternExecutor *patternExecutor = new PatternExecutor(fileExecutor,
//                                                           "C:\\Users\\djnic\\git\\SuffixTable\\testFiles",
//                                                           "C:\\Users\\djnic\\git\\SuffixTable\\testFiles\\patternFile-camel.txt",
//                                                           "C:\\Users\\djnic\\git\\SuffixTable\\testFiles\\textFile-camel.txt");
//    AlgorithmExecutor *algorithmExecutor = new AlgorithmExecutor();
//    algorithmExecutor->setAlgorithm(new SuffixTableAlgorithm(
//            fileExecutor->loadTextFile("C:\\Users\\djnic\\git\\SuffixTable\\testFiles\\textFile-camel.txt")));
//    patternExecutor->findAll(algorithmExecutor->execute());

    // View template
    Controller *controller = new Controller();
    controller->initializeApp();

    int algorithm = -1;
    std::string pathToTextFile, pathToPatterFile, pathToResultFile;
    std::cout << "Wybierz algorytm: Tablica Sufiksow [0], Tablica LCP [1]: ";
    while (algorithm != 0 && algorithm != 1)
        std::cin >> algorithm;
    std::cout << std::endl;

    std::cout << "Podaj sciezke do pliku z tekstem: ";
    std::cin >> pathToTextFile;
    std::cout << std::endl;

    std::cout << "Podaj sciezke do pliku ze wzorcami: ";
    std::cin >> pathToPatterFile;
    std::cout << std::endl;

    std::cout << "Podaj sciezke do pliku wynikowego: ";
    std::cin >> pathToResultFile;
    std::cout << std::endl;

    controller->setPathToTextFile(pathToTextFile);
    controller->setPathToPatternFile(pathToPatterFile);
    controller->setPathToResultFile(pathToResultFile);
    controller->setAlgorithmExecutor(std::to_string(algorithm));

    for (double i = 0; i <= 1; i += 0.25)
        printProgress(i);

    std::cout << "Generacja wynikow... " << std::endl;
    if (controller->generateResults())
        std::cout << "Proces generacji zakonczyl sie pozytywnie! " << std::endl;
    else
        std::cerr << "Wystapil blad podczas generacji wynikow! " << std::endl;

    controller->shutDownApp();

    return 0;
}
