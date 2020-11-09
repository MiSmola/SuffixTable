//
// Created by djnic on 26.10.2020.
//

#ifndef SUFFIXTABLE_ALGORITHMEXECUTOR_H
#define SUFFIXTABLE_ALGORITHMEXECUTOR_H


#include "Algorithm.h"

class AlgorithmExecutor {
    Algorithm *algorithm;
public:
    PTable *execute();

    void setAlgorithm(Algorithm *_algorithm);
};


#endif //SUFFIXTABLE_ALGORITHMEXECUTOR_H
