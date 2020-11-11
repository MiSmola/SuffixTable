//
// Created by djnic on 09.11.2020.
//

#include <iostream>
#include "Controller.h"
#include "Constants.h"
#include "../model/SuffixTableAlgorithm.h"
#include "../model/LCPTableAlgorithm.h"


void Controller::runApp(int argc, char *argv[]) {
    view->startupApp(argc, argv);
    populateParameters();
    generateResults();
    shutDownApp();
}

void Controller::populateParameters() {
    pathToTextFile = view->getTextFilePath();
    pathToResultFile = view->getResultFilePath();
    pathToPatternFile = view->getPatternFilePath();
    setAlgorithmExecutor(view->getAlgorithm());
}

bool Controller::generateResults() {
    bool result = false;
    if (!pathToTextFile.empty() && !pathToResultFile.empty() && !pathToPatternFile.empty()) {
        this->patternExecutor = new PatternExecutor(this->fileExecutor, this->pathToResultFile,
                                                    this->pathToPatternFile, this->pathToTextFile);
        result = patternExecutor->findAll(this->algorithmExecutor->execute());
    } else
        std::cerr << APP_LOGGER_SEVERE_PREFIX << "Files paths are not set" << std::endl;
    return result;
}

void Controller::shutDownApp() {
    view->shutdownApp();
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
        std::cerr << APP_LOGGER_SEVERE_PREFIX << "The algorithm or path to text file is not set" << std::endl;
}

Controller::~Controller() {
    delete fileExecutor;
    delete algorithmExecutor;
    delete patternExecutor;
    delete view;
}


