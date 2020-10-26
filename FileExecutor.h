//
// Created by djnic on 26.10.2020.
//

#ifndef SUFFIXTABLE_FILEEXECUTOR_H
#define SUFFIXTABLE_FILEEXECUTOR_H


#include <xstring>

class FileExecutor {
public:
    void createResultFile();

    std::string loadTextFile();

    std::string* loadPatternFile();
};


#endif //SUFFIXTABLE_FILEEXECUTOR_H
