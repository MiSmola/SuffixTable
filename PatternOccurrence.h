//
// Created by djnic on 27.10.2020.
//

#ifndef SUFFIXTABLE_PATTERNOCCURRENCE_H
#define SUFFIXTABLE_PATTERNOCCURRENCE_H

// TODO: struct of pattern and its occurrences as the int array

#include <string>

struct patternOccurrence {
    patternOccurrence();

    std::string pattern;
    int *occurences;
    int numberOfOccurrences;

    patternOccurrence(const std::string &pattern, int *occurences, int numberOfOccurrences);
};

class PatternOccurrence {
    // TODO: array of the struct objects
    patternOccurrence *patternOccurrence = nullptr;
    int patternOccurrenceSize;
    int patternCount;
public:
    PatternOccurrence();

    void add(std::string _pattern, int *_occurences, int _numberOfOccurrences);

    // TODO: add() method - adds new pattern occurrence to the array
    // dodanie nowego patternOccurrence do getPatternOccurrence
    struct patternOccurrence *getPatternOccurrence() const;
    // TODO: get...() method - accessor to the field mentioned in the first line
    // getPatternOccurrence

    int getPatternCount() const;
};


#endif //SUFFIXTABLE_PATTERNOCCURRENCE_H
