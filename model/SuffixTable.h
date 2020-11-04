//
// Created by djnic on 04.11.2020.
//

#ifndef SUFFIXTABLE_SUFFIXTABLE_H
#define SUFFIXTABLE_SUFFIXTABLE_H

#include <string>
#include "PTable.h"
#include "List.h"

struct SuffixTableRow {
    int index;
    std::string suffix;
};

class SuffixTable : public PTable {
    std::string *text; // TODO: Move to SuffixAlgorithm
//    int length; // TODO: Check if can be removed
//    int *index; // TODO: Consider struct instead of two arrays, use List
//    std::string *suffix; // TODO: Consider struct instead of two arrays, use List
    List<SuffixTableRow> suffixes;
public:
    // TODO: Check parameters and implement
    void add(SuffixTableRow suffixTableRow);

    std::string *getText() const;

    int getLength() const;

    int *getIndex() const;

    std::string *getSuffix() const;

    void setText(std::string *text);

    void setLength(int length);

    void setIndex(int *index);

    void setSuffix(std::string *suffix);
};


#endif //SUFFIXTABLE_SUFFIXTABLE_H
