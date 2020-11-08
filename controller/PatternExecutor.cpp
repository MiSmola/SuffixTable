//
// Created by djnic on 06.11.2020.
//

#include <iostream>
#include "PatternExecutor.h"
#include "../model/SuffixTable.h"

PatternExecutor::PatternExecutor(FileExecutor *fileExecutor, std::string pathToResultFile,
                                 std::string pathToPatternFile, std::string pathToTextFile)
        : fileExecutor(fileExecutor),
          pathToResultFile(pathToResultFile),
          patterns(fileExecutor->loadPatternFile(pathToPatternFile)),
          text(fileExecutor->loadTextFile(pathToTextFile)) {
    std::cout << "LOGGER [PatternExecutor] " << this->patterns.to_string() << std::endl;
    std::cout << "LOGGER [PatternExecutor] " << this->text << std::endl;
}

bool PatternExecutor::findAll(PTable *pTable) {
    std::cout << "LOGGER [PatternExecutor] " << "findAll process using... "
              << static_cast<SuffixTable *>(pTable)->to_string() << std::endl;
    std::string *suffixes = static_cast<SuffixTable *>(pTable)->getSuffix();
    int *indexes = static_cast<SuffixTable *>(pTable)->getIndex();
    int length = static_cast<SuffixTable *>(pTable)->getLength();

    // TODO: Implement binary search
    // TODO: Implement range check to enable occurrences counting
    // TODO: Create result file (filExecutor method) - remember about PatternOccurrences obj

    List<PatternOccurrence> patternOccurrences;
    List<int> occurrences;

    for (int i = 0; i < patterns.getSize(); i++) {
        std::string currentPattern = this->patterns.get(i);
        int patternBeginningIndex = 0, patternEndingIndex = length;
        int lowValueIndex, middleValueIndex = length, highValueIndex = length, temporaryPatternLength = currentPattern.length();

        if (currentPattern.compare(0, temporaryPatternLength, suffixes[(int) middleValueIndex / 2]) == 0) {
            for (int i = 0; i < middleValueIndex / 2; i++) {
                if (currentPattern.compare(0, temporaryPatternLength, suffixes[i]) == 0) {
                    patternBeginningIndex = i;
                    i++;
                    while (currentPattern.compare(0, temporaryPatternLength, suffixes[i]) ==
                           0) { //i wyszukuje wszystkie
                        patternEndingIndex = i;
                        i++;
                    }
                }
            }
        }
        middleValueIndex = (middleValueIndex - 1) / 2;
        while (currentPattern.compare(suffixes[(int) middleValueIndex].substr(0, temporaryPatternLength)) != 0) {
            // TODO: Use own lolower(string) method for current pattern and suffixed(middleValueIndex)
            if (currentPattern.compare(suffixes[(int) middleValueIndex].substr(0, temporaryPatternLength)) < 0) {
                highValueIndex = middleValueIndex;
                middleValueIndex = (0 + highValueIndex) / 2;
            }
            if (currentPattern.compare(suffixes[(int) middleValueIndex].substr(0, temporaryPatternLength)) > 0) {
                lowValueIndex = middleValueIndex;
                middleValueIndex = (lowValueIndex + length - 1) / 2;
            }
        }

        int j = middleValueIndex;
        while (currentPattern.compare(suffixes[j].substr(0, temporaryPatternLength)) == 0) {
            occurrences.add(indexes[j]);
            j--;
        }
        j = middleValueIndex + 1;
        while (currentPattern.compare(suffixes[j].substr(0, temporaryPatternLength)) == 0) {
            occurrences.add(indexes[j]);
            j++;
        }

        patternOccurrences.add(PatternOccurrence(currentPattern, occurrences));
    }

    fileExecutor->
            createResultFile(pathToResultFile, patternOccurrences
    );
    return true;
}

void PatternExecutor::setFileExecutor(FileExecutor *fileExecutor) {
    PatternExecutor::fileExecutor = fileExecutor;
}
