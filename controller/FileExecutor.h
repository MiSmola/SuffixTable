//
// Created by djnic on 26.10.2020.
//

#ifndef SUFFIXTABLE_FILEEXECUTOR_H
#define SUFFIXTABLE_FILEEXECUTOR_H


#include <xstring>
#include "../model/PatternOccurrence.h"

class FileExecutor {
public:
    std::string createResultFile(std::string pathToFile, List<PatternOccurrence> patternOccurrence);

    std::string loadTextFile(std::string pathToSourceFile);

    List<std::string> loadPatternFile(std::string pathToPatternFile);
};

#endif //SUFFIXTABLE_FILEEXECUTOR_H
