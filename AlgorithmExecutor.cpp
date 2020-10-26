//
// Created by djnic on 26.10.2020.
//

#include "AlgorithmExecutor.h"

void AlgorithmExecutor::setAlgorithm(Algorithm *_algorithm) {
    this->algorithm = _algorithm;
}

PTable AlgorithmExecutor::execute() {
    return algorithm->execute();
}
