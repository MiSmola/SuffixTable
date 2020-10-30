//
// Created by djnic on 27.10.2020.
//

#include <iostream>
#include "PatternOccurrence.h"

PatternOccurrence::PatternOccurrence() {
    struct patternOccurrence *patoc = new struct patternOccurrence[1];
    this->patternOccurrence = patoc;
    this->patternOccurrenceSize = 1;
    this->patternCount = 0;
}

int PatternOccurrence::getPatternCount() const {
    return patternCount;
}

void PatternOccurrence::add(std::string _pattern, int *_occurences, int _numberOfOccurrences) {
    if (patternCount != patternOccurrenceSize) {
        struct patternOccurrence po(_pattern, _occurences, _numberOfOccurrences);
        this->patternOccurrence[0] = po;
        this->patternCount++;
    } else
        std::cerr << "The array can store only " << patternCount << " patterns" << std::endl;
}

patternOccurrence *PatternOccurrence::getPatternOccurrence() const {
    return patternOccurrence;
}

patternOccurrence::patternOccurrence(const std::string &pattern, int *occurences, int numberOfOccurrences) : pattern(
        pattern), occurences(occurences), numberOfOccurrences(numberOfOccurrences) {}

patternOccurrence::patternOccurrence() {}
