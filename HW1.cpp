#include "Console.h"
#include "CommandProcessor.h"
#include <iostream>

int main() {
    Console console;
    CommandProcessor processor;
    std::string input;
    console.printDefaultDisplay();

    while (true) {
        std::cout << "Enter a command: ";
        console.setColor(7);  // Reset to white

        std::getline(std::cin, input);

        if (!input.empty()) {
            bool keepRunning = processor.executeCommand(input, console);
            if (!keepRunning)
                break;
        }
    }
    return 0;
}
