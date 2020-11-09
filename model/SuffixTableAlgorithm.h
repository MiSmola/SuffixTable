//
// Created by djnic on 26.10.2020.
//

#ifndef SUFFIXTABLE_SUFFIXTABLEALGORITHM_H
#define SUFFIXTABLE_SUFFIXTABLEALGORITHM_H


#include "Algorithm.h"

class SuffixTableAlgorithm : public Algorithm {
    std::string text;
    std::string *textCharacters;
    int length;
    int *index;
    std::string *suffix;
public:
    SuffixTableAlgorithm(std::string text);

    PTable *execute();
};


#endif //SUFFIXTABLE_SUFFIXTABLEALGORITHM_H
