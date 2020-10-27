//
// Created by djnic on 26.10.2020.
//

#include <sstream>
#include <fstream>
#include <iostream>
#include "FileExecutor.h"
#include "PatternOccurrence.h"

std::string FileExecutor::createResultFile(std::string pathToFile, patternOccurrence *patternOccurrence) {
    //// TODO: pass file name with path as the parameter and return path to the file (include file name f.eg. C:\Users\harrypotter\blyskawica\hagrid.txt)
    std::string s;
    std::ofstream file("resultFile.txt");
    file.open("C:\\Users\\djnic\\git\\SuffixTable\\resultFile.txt");
    if (file.good()) std::cout << "C:\\Users\\djnic\\git\\SuffixTable\\resultFile.txt" << std::endl;
    else
        std::ofstream file("C:\\Users\\djnic\\git\\SuffixTable\\resultFile.txt");
    // TODO: PatternOccurrence object as the method parameter, occurrences should be written in the output file
    int i = 0;

    while (patternOccurrence) {
        s = patternOccurrence[i].pattern + ": ";
        if (patternOccurrence[i].occurences = 0) s += "brak";
        for (int j = 0; j < patternOccurrence[i].numberOfOccurrences; j++) {
            s += (patternOccurrence[i].occurences[j] + ", ");
        }
        i++;
    }
    file << s;
    std::cout << "Result file path: ";
    return pathToFile;
}

std::string FileExecutor::loadTextFile() {
    // TODO: pass file as the parameter
    // TODO: ignore white characters except space
    std::ifstream file("test.txt");
    std::string s;
    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, s);
            std::cout << s << std::endl;
        }
    } else
        std::cerr << "File " << "test.txt" << " can't be opened..." << std::endl;
    file.close();
    return s;
}

std::string *FileExecutor::loadPatternFile() {
    std::ifstream file("test.txt");
    std::string s;
    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, s);
            std::cout << s << std::endl;
        }
    } else
        std::cerr << "File " << "test.txt" << " can't be opened..." << std::endl;
    file.close();
    return new std::string[0];
}

