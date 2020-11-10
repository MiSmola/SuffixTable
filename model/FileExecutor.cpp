//
// Created by djnic on 26.10.2020.
//

#include <iostream>
#include <fstream>
#include <string>
#include "FileExecutor.h"
#include "../view/ResourceBundle.h"


std::string FileExecutor::createResultFile(std::string pathToFile, List<PatternOccurrence> patternOccurrence) {
    std::string patterns;
    std::ofstream file;
    file.open(pathToFile + "\\resultFile.txt", std::ios_base::app);
    if (file.is_open()) {
        for (int i = 0; i < patternOccurrence.getSize(); i++) {
            patterns += patternOccurrence.get(i).getPattern() + ": ";
            if (patternOccurrence.get(i).getOccurrences().isEmpty()) patterns += "brak";
            for (int j = 0; j < patternOccurrence.get(i).getOccurrences().getSize(); j++)
                patterns += (std::to_string(patternOccurrence.get(i).getOccurrences().get(j)) + ", ");
            patterns += "\n";
        }
        file << patterns;
        file.close();
    } else
        std::cerr << APP_LOGGER_SEVERE_PREFIX << "Error opening file" << std::endl;
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
    } else
        std::cerr << APP_LOGGER_SEVERE_PREFIX << "File " << pathToSourceFile << " can't be opened..." << std::endl;
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
        }
    else
        std::cerr << APP_LOGGER_SEVERE_PREFIX << "File " << pathToPatternFile << " can't be opened..." << std::endl;
    file.close();
    return listOfPatterns;
}

