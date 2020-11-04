//
// Created by djnic on 26.10.2020.
//

#include <iostream>
#include <fstream>
#include <string>
#include "FileExecutor.h"


std::string FileExecutor::createResultFile(std::string pathToFile, List<PatternOccurrence> patternOccurrence) {
    std::string patterns;
    std::ofstream file;
    file.open(pathToFile + "\\resultFile.txt");
    if (file.is_open()) {
        for (int i = 0; i < patternOccurrence.getSize(); i++) {
            patterns = patternOccurrence.get(i).getPattern() + ": ";
            if (patternOccurrence.get(i).getOccurrences().isEmpty()) patterns += "brak";
            for (int j = 0; j < patternOccurrence.get(i).getOccurrences().getSize(); j++)
                patterns += (std::to_string(patternOccurrence.get(i).getOccurrences().get(j)) + ", ");
            i++;
        }
        file << patterns;
        file.close();
    } else
        std::cerr << "Error opening file" << std::endl;
    return pathToFile;
}

std::string FileExecutor::loadTextFile(std::string pathToSourceFile) {
    std::ifstream file(pathToSourceFile);
    std::string line, result;
    if (file.is_open()) {
        while (!file.eof()) {
            getline(file, line);
            result += line;
        }
        std::cout << result << std::endl;
    } else
        // TODO: pass file name into the cerr
        std::cerr << "File " << "test.txt" << " can't be opened..." << std::endl;
    file.close();
    return result;
}

List<std::string> FileExecutor::loadPatternFile(std::string pathToPatternFile) {
    std::ifstream file(pathToPatternFile);
    std::string line;
    List<std::string> listOfPatterns;
    if (file.is_open())
        while (!file.eof()) {
            getline(file, line);
            listOfPatterns.add(line);
            std::cout << line << std::endl;
        }
    else
        // TODO: pass file name into the cerr
        std::cerr << "File " << "test.txt" << " can't be opened..." << std::endl;
    file.close();
    return listOfPatterns;
}

