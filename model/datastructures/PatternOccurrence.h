//
// Created by djnic on 27.10.2020.
//

#ifndef SUFFIXTABLE_PATTERNOCCURRENCE_H
#define SUFFIXTABLE_PATTERNOCCURRENCE_H

#include <string>
#include "List.h"

class PatternOccurrence {
    std::string pattern;

    List<int> occurrences;
public:
    PatternOccurrence();

    PatternOccurrence(const std::string &pattern, List<int> occurrences);

    const std::string &getPattern() const;

    List<int> &getOccurrences();
};

#endif //SUFFIXTABLE_PATTERNOCCURRENCE_H
