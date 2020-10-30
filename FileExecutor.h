//
// Created by djnic on 26.10.2020.
//

#ifndef SUFFIXTABLE_FILEEXECUTOR_H
#define SUFFIXTABLE_FILEEXECUTOR_H


#include <xstring>
#include "PatternOccurrence.h"

class FileExecutor {
public:
    std::string createResultFile(std::string pathToFile, PatternOccurrence *patternOccurrence);

    std::string loadTextFile();

    std::string *loadPatternFile();
};


#endif //SUFFIXTABLE_FILEEXECUTOR_H
