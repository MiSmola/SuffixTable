//
// Created by djnic on 26.10.2020.
//

#include <iostream>
#include <fstream>
#include "FileExecutor.h"
#include "PatternOccurrence.h"

std::string FileExecutor::createResultFile(std::string pathToFile, PatternOccurrence *patternOccurrence) {
    // TODO: pass file name with path as the parameter and return path to the file (include file name f.eg. C:\Users\harrypotter\blyskawica\hagrid.txt)
    std::string s;
    std::ofstream file;
    file.open(pathToFile + "\\resultFile.txt");
    // TODO: PatternOccurrence object as the method parameter, occurrences should be written in the output file
    if (file.is_open()) {
        int i = 0;
        struct patternOccurrence *patternOccurrenceStructure = patternOccurrence->getPatternOccurrence();
        while (i != patternOccurrence->getPatternCount()) {
            s = patternOccurrenceStructure[i].pattern + ": ";
            if (patternOccurrenceStructure[i].occurences == 0) s += "brak";
            for (int j = 0; j < patternOccurrenceStructure[i].numberOfOccurrences; j++)
                s += (std::to_string(patternOccurrenceStructure[i].occurences[j]) + ", ");
            i++;
        }
        file << s;
        file.close();
    } else
        std::cerr << "Error opening file";
    return pathToFile;
}

std::string FileExecutor::loadTextFile() {
    // TODO: pass file as the parameter
    // TODO: ignore white characters except space
    std::ifstream file("test.txt");
    std::string s;
    if (file.is_open())
        while (!file.eof()) {
            getline(file, s);
            std::cout << s << std::endl;
        }
    else
        std::cerr << "File " << "test.txt" << " can't be opened..." << std::endl;
    file.close();
    return s;
}

std::string *FileExecutor::loadPatternFile() {
    std::ifstream file("test.txt");
    std::string s;
    if (file.is_open())
        while (!file.eof()) {
            getline(file, s);
            std::cout << s << std::endl;
        }
    else
        std::cerr << "File " << "test.txt" << " can't be opened..." << std::endl;
    file.close();
    return new std::string[0];
}

