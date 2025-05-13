#ifndef CLI_APPLICATION_H
#define CLI_APPLICATION_H

#include "Console.h"
#include "CommandProcessor.h"

class CLIApp {
public:
    void run();
private:
    Console console;
    CommandProcessor processor;
};

#endif
