//
// Created by djnic on 27.10.2020.
//

#include "PatternOccurrence.h"

patternOccurrence *PatternOccurrence::getPatternOccurrence() const {
    return patternOccurrence;
}

void PatternOccurrence::add(std::string _pattern, int *_occurences, int _numberOfOccurrences) {
    struct patternOccurrence po(_pattern, _occurences, _numberOfOccurrences);
    this->patternOccurrence[0] = po; // FIXME
}

patternOccurrence::patternOccurrence(const std::string &pattern, int *occurences, int numberOfOccurrences) : pattern(
        pattern), occurences(occurences), numberOfOccurrences(numberOfOccurrences) {}
