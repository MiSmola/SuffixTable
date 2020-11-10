#include <iostream>
#include "controller/Controller.h"

int main(int argc, char *argv[]) {
    Controller *controller = new Controller();
    controller->runApp(argc, argv);
    return 0;
}
