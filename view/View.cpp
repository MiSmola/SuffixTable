//
// Created by djnic on 10.11.2020.
//

#include <iostream>
#include <thread>
#include "View.h"

#define PBWIDTH 60
#define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"

void View::displayWelcomeScreen() {
    std::cout << WELCOME_BANNER << std::endl;
}

void View::displayInstructionScreen() {
    std::cout << INSTRUCTIONS << std::endl;
}

void View::displayStatusScreen() {
    for (double i = 0; i <= 1; i += 0.25)
        printProgress(i);
    std::cout << STATUS << std::endl;
}

void View::displayEndScreen() {
    std::cout << END << std::endl;
}

void View::fetchParametersAndPopulateInputFields(int argc, char *argv[]) {
    if (argc == 7) {
        for (int i = 1; i < argc; ++i) {
            std::string arg = argv[i];
            if ((arg == "-t") || (arg == "--textFile"))
                this->textFilePath = argv[i + 1];
            else if ((arg == "-p") || (arg == "--patternFile"))
                this->patternFilePath = argv[i + 1];
            else if ((arg == "-o") || (arg == "--resultFile"))
                this->resultFilePath = argv[i + 1];
        }
    } else
        std::cerr << "[SEVERE] The number of command line parameters is incorrect" << std::endl;
}

void View::printProgress(double percentage) {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    int val = (int) (percentage * 100);
    int lpad = (int) (percentage * PBWIDTH);
    int rpad = PBWIDTH - lpad;
    printf("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
    fflush(stdout);
}

void View::startupApp(int argc, char *argv[]) {
    fetchParametersAndPopulateInputFields(argc, argv);
    displayWelcomeScreen();
    displayInstructionScreen();
}

void View::shutdownApp() {
    displayStatusScreen();
    displayEndScreen();
}

const std::string &View::getAlgorithm() const {
    return algorithm;
}

const std::string &View::getTextFilePath() const {
    return textFilePath;
}

const std::string &View::getPatternFilePath() const {
    return patternFilePath;
}

const std::string &View::getResultFilePath() const {
    return resultFilePath;
}
