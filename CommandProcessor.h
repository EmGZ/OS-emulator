#ifndef COMMAND_PROCESSOR_H
#define COMMAND_PROCESSOR_H

#include <string>
#include <unordered_set>
#include "Console.h"

class CommandProcessor {
public:
    bool executeCommand(const std::string& cmd, Console& console);
};

#endif