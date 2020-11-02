//
// Created by djnic on 27.10.2020.
//

#include <iostream>
#include "PatternOccurrence.h"

PatternOccurrence::PatternOccurrence() {}

PatternOccurrence::PatternOccurrence(const std::string &pattern, List<int> occurrences) : pattern(
        pattern), occurrences(occurrences) {}

const std::string &PatternOccurrence::getPattern() const {
    return pattern;
}

List<int> &PatternOccurrence::getOccurrences() {
    return occurrences;
}