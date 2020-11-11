//
// Created by djnic on 04.11.2020.
//
#include <iostream>
#include "SuffixTable.h"
#include "../../view/ResourceBundle.h"

SuffixTable::SuffixTable(int *index, std::string *suffix, int length) : index(index), suffix(suffix), length(length) {}

SuffixTable::SuffixTable(int length) : length(length), index(new int[length]), suffix(new std::string[length]) {}

void SuffixTable::add(int index, std::string suffix, int idx) {
    if (index < length) {
        this->index[idx] = index;
        this->suffix[idx] = suffix;
    } else
        std::cerr << APP_LOGGER_SEVERE_PREFIX << "Array out of bound, the suffix cannot be added" << std::endl;
}

std::string SuffixTable::to_string() {
    std::string result = "";
    if (length > 0)
        for (int iterate = 0; iterate < length; iterate++)
            result += (suffix[iterate] + "\t" + std::to_string(index[iterate]) + "\n");
    return result;
}

int *SuffixTable::getIndex() const {
    return index;
}

void SuffixTable::setIndex(int *index) {
    SuffixTable::index = index;
}

std::string *SuffixTable::getSuffix() const {
    return suffix;
}

void SuffixTable::setSuffix(std::string *suffix) {
    SuffixTable::suffix = suffix;
}

int SuffixTable::getLength() const {
    return length;
}

void SuffixTable::setLength(int length) {
    SuffixTable::length = length;
}

SuffixTable::~SuffixTable() {
    delete[] index;
    delete[] suffix;
}
