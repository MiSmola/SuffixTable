//
// Created by djnic on 26.10.2020.
//

#include <iostream>
#include "SuffixTableAlgorithm.h"
#include "datastructures/SuffixTable.h"

SuffixTableAlgorithm::SuffixTableAlgorithm(std::string text) : text(text) {
    this->textCharacters = new std::string[text.length()];
    for (int i = 0; i < text.length(); i++)
        this->textCharacters[i] = text.substr(i, 1);
    this->length = text.length();
    this->index = new int[length];
    for (int i = 0; i < length; i++) {
        index[i] = i;
    }
    suffix = new std::string[length];
}

PTable *SuffixTableAlgorithm::execute() {
    // FIXME: Don't startupApp more multiple times
    std::cout << APP_LOGGER_INFO_PREFIX << " [SuffixTableAlgorithm] algorithm executed" << std::endl;
    for (int index = 0; index < length; index++) {
        std::string text = "";
        for (int text_index = index; text_index < length; text_index++) {
            text += this->textCharacters[text_index];
        }
        suffix[index] = text;
    }
    int back;
    for (int iteration = 1; iteration < length; iteration++) {
        std::string key = suffix[iteration];
        int keyindex = index[iteration];
        for (back = iteration - 1; back >= 0; back--) {
            if (suffix[back].compare(key) > 0) {
                suffix[back + 1] = suffix[back];
                index[back + 1] = index[back];
            } else
                break;
        }
        suffix[back + 1] = key;
        index[back + 1] = keyindex;
    }
    return new SuffixTable(index, suffix, length);
}

SuffixTableAlgorithm::~SuffixTableAlgorithm() {
    delete[] textCharacters;
    delete[] index;
    delete[] suffix;
}
