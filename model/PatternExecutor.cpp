//
// Created by djnic on 06.11.2020.
//

#include <iostream>
#include "PatternExecutor.h"
#include "datastructures/SuffixTable.h"

PatternExecutor::PatternExecutor(FileExecutor *fileExecutor, std::string pathToResultFile,
                                 std::string pathToPatternFile, std::string pathToTextFile)
        : fileExecutor(fileExecutor),
          pathToResultFile(pathToResultFile),
          patterns(fileExecutor->loadPatternFile(pathToPatternFile)),
          text(fileExecutor->loadTextFile(pathToTextFile)) {
    std::cout << APP_LOGGER_INFO_PREFIX << " [PatternExecutor] " << this->patterns.to_string() << std::endl;
    std::cout << APP_LOGGER_INFO_PREFIX << " [PatternExecutor] " << this->text << std::endl;
}

bool PatternExecutor::findAll(PTable *pTable) {
    std::cout << APP_LOGGER_INFO_PREFIX << " [PatternExecutor] " << "findAll process using... \n"
              << static_cast<SuffixTable *>(pTable)->to_string() << std::endl;
    std::string *suffixes = static_cast<SuffixTable *>(pTable)->getSuffix();
    int *indexes = static_cast<SuffixTable *>(pTable)->getIndex();
    int length = static_cast<SuffixTable *>(pTable)->getLength();


    List<PatternOccurrence> patternOccurrences;
    List<int> occurrences;

    for (int i = 0; i < patterns.getSize(); i++) {
        std::string currentPattern = this->patterns.get(i);
        int patternBeginningIndex = 0, patternEndingIndex = length;
        int lowValueIndex, middleValueIndex = length, highValueIndex =
                length - 1, temporaryPatternLength = currentPattern.length();

        if (currentPattern.compare(0, temporaryPatternLength, suffixes[(int) middleValueIndex / 2]) == 0) {
            for (int i = 0; i < middleValueIndex / 2; i++) {
                if (currentPattern.compare(0, temporaryPatternLength, suffixes[i]) == 0) {
                    patternBeginningIndex = i;
                    i++;
                    while (currentPattern.compare(0, temporaryPatternLength, suffixes[i]) ==
                           0) {
                        patternEndingIndex = i;
                        i++;
                    }
                }
            }
        }
        middleValueIndex = (length - 1) / 2;
        lowValueIndex = 0;
        highValueIndex = length - 1;
        while (currentPattern.compare(suffixes[(int) middleValueIndex].substr(0, temporaryPatternLength)) != 0
               && highValueIndex - lowValueIndex > 1) {
            // TODO: Use own tolower(string) method for current pattern and suffixes(middleValueIndex)
            if (currentPattern.compare(suffixes[(int) middleValueIndex].substr(0, temporaryPatternLength)) < 0) {
                highValueIndex = middleValueIndex;
                middleValueIndex = (highValueIndex - lowValueIndex) / 2 + lowValueIndex;
                continue;
            }
            if (currentPattern.compare(suffixes[(int) middleValueIndex].substr(0, temporaryPatternLength)) > 0) {
                lowValueIndex = middleValueIndex;
                middleValueIndex = (((length - 1) - lowValueIndex + 1) / 2) + lowValueIndex;
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

    fileExecutor->createResultFile(pathToResultFile, patternOccurrences);
    return true;
}

void PatternExecutor::setFileExecutor(FileExecutor *fileExecutor) {
    PatternExecutor::fileExecutor = fileExecutor;
}
