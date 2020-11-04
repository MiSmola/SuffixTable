//
// Created by djnic on 04.11.2020.
//

#include "SuffixTable.h"

std::string *SuffixTable::getText() const {
    return text;
}

void SuffixTable::setText(std::string *text) {
    SuffixTable::text = text;
}

void SuffixTable::add(SuffixTableRow suffixTableRow) {
    this->suffixes.add(suffixTableRow);
}
