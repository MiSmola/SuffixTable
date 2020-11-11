//
// Created by djnic on 04.11.2020.
//

#ifndef SUFFIXTABLE_SUFFIXTABLE_H
#define SUFFIXTABLE_SUFFIXTABLE_H

#include <string>
#include "PTable.h"
#include "List.h"

class SuffixTable : public PTable {
    int *index; // TODO: change to the List if possible
    std::string *suffix; // TODO: change to the List if possible
    int length;
public:
    SuffixTable(int *index, std::string *suffix, int length);

    virtual ~SuffixTable();

    SuffixTable(int length);

    int *getIndex() const;

    void setIndex(int *index);

    std::string *getSuffix() const;

    void setSuffix(std::string *suffix);

    int getLength() const;

    void setLength(int length);

    void add(int index, std::string suffix, int idx);

    std::string to_string();
};


#endif //SUFFIXTABLE_SUFFIXTABLE_H
