//
// Created by djnic on 26.10.2020.
//

#include <iostream>
#include "LCPTableAlgorithm.h"
#include "../view/ResourceBundle.h"

PTable *LCPTableAlgorithm::execute() {
    std::cout << APP_LOGGER_INFO_PREFIX << " LCPTableAlgorithm algorithm executed" << std::endl;
    return new PTable();
}
