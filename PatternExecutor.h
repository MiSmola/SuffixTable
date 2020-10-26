//
// Created by djnic on 26.10.2020.
//

#ifndef SUFFIXTABLE_PATTERNEXECUTOR_H
#define SUFFIXTABLE_PATTERNEXECUTOR_H


#include "FileExecutor.h"
#include "PTable.h"

class PatternExecutor {
    FileExecutor *fileExecutor;
public:
    bool findAll(PTable *pTable);

    void setFileExecutor(FileExecutor *fileExecutor);
};


#endif //SUFFIXTABLE_PATTERNEXECUTOR_H
