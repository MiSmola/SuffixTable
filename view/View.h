//
// Created by djnic on 10.11.2020.
//

#ifndef SUFFIXTABLE_VIEW_H
#define SUFFIXTABLE_VIEW_H


#include "ResourceBundle.h"
#include "../controller/Constants.h"

class View {
    ResourceBundle resourceBundle;
    std::string algorithm = SUFFIX_TABLE;
    std::string textFilePath;
    std::string patternFilePath;
    std::string resultFilePath;

public:
    void displayWelcomeScreen();

    void displayInstructionScreen();

    void displayStatusScreen();

    void displayEndScreen();

    void fetchParametersAndPopulateInputFields(int argc, char *argv[]);

    void printProgress(double percentage);

    void startupApp(int argc, char *argv[]);

    void shutdownApp();

    const std::string &getAlgorithm() const;

    const std::string &getTextFilePath() const;

    const std::string &getPatternFilePath() const;

    const std::string &getResultFilePath() const;
};


#endif //SUFFIXTABLE_VIEW_H
