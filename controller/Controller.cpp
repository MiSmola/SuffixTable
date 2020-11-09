//
// Created by djnic on 09.11.2020.
//

#include <iostream>
#include "Controller.h"
#include "Constants.h"
#include "../model/SuffixTableAlgorithm.h"
#include "../model/LCPTableAlgorithm.h"


void Controller::initializeApp() {
    std::cout << "           _             ______                      _   " << std::endl;
    std::cout << "     /\\   | |           |  ____|                    | |  " << std::endl;
    std::cout << "    /  \\  | | __ _  ___ | |__  __  ___ __   ___ _ __| |_ " << std::endl;
    std::cout << "   / /\\ \\ | |/ _` |/ _ \\|  __| \\ \\/ / '_ \\ / _ \\ '__| __|" << std::endl;
    std::cout << "  / ____ \\| | (_| | (_) | |____ >  <| |_) |  __/ |  | |_ " << std::endl;
    std::cout << " /_/    \\_\\_|\\__, |\\___/|______/_/\\_\\ .__/ \\___|_|   \\__|" << std::endl;
    std::cout << "              __/ |                 | |                  " << std::endl;
    std::cout << "             |___/                  |_|                  " << std::endl;
}

bool Controller::generateResults() {
    bool result = false;
    if (!pathToTextFile.empty() && !pathToResultFile.empty() && !pathToPatternFile.empty()) {
        this->patternExecutor = new PatternExecutor(this->fileExecutor, this->pathToResultFile,
                                                    this->pathToPatternFile, this->pathToTextFile);
        result = patternExecutor->findAll(this->algorithmExecutor->execute());
    } else
        std::cerr << "[SEVERE] Files paths are not set" << std::endl;
    return result;
}

void Controller::shutDownApp() {
    std::cout << "Plik zapisany pod sciezka: " << pathToResultFile << std::endl;
    std::cout << "Program zakonczyl dzialanie. " << std::endl;
}

void Controller::setPathToTextFile(const std::string &pathToTextFile) {
    Controller::pathToTextFile = pathToTextFile;
}

void Controller::setPathToResultFile(const std::string &pathToResultFile) {
    Controller::pathToResultFile = pathToResultFile;
}

void Controller::setPathToPatternFile(const std::string &pathToPatternFile) {
    Controller::pathToPatternFile = pathToPatternFile;
}

void Controller::setAlgorithmExecutor(const std::string algorithm) {
    if (!algorithm.empty() && !this->pathToTextFile.empty()) {
        if (algorithm == SUFFIX_TABLE) {
            this->algorithmExecutor = new AlgorithmExecutor();
            this->algorithmExecutor->setAlgorithm(new SuffixTableAlgorithm(
                    fileExecutor->loadTextFile(this->pathToTextFile)));
        } else if (algorithm == LCP_TABLE) {
            this->algorithmExecutor = new AlgorithmExecutor();
            this->algorithmExecutor->setAlgorithm(new LCPTableAlgorithm());
        }
    } else
        std::cerr << "[SEVERE] The algorithm or path to text file is not set" << std::endl;
}


