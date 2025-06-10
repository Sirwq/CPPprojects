#include <iostream>
#include <iomanip>
#include <cstring>
#include "Person.hpp"

enum class Command {ADD, SEARCH, EXIT, NON};

void menu() {
    int top = -1;
    Person* contacts[8] = {nullptr};

    while (true) {
        Command command;
        char input[7];
        std::cin >> std::setw(7) >> input;

        if (!strncmp(input, "ADD", 3)) {
            command = Command::ADD;
        } else if (!strncmp(input, "SEARCH", 6)) {
            command = Command::SEARCH;
        } else if (!strncmp(input, "EXIT", 4)) {
            for (int i = 0; i <= top; i++) {
                delete contacts[i];
            }
            command = Command::EXIT;
        } else {
            command = Command::NON;
        }
        
        switch(command) {
            case Command::ADD:
                if (top >= 7) {
                    std::cout << "Contact list is full." << std::endl;
                    continue;
                }
                ++top;
                contacts[top] = new Person;
                Person::createPers(*contacts[top]);
                break;
            case Command::SEARCH:
                std::cout << "Index | Name | Lastname | Login | Address\n";
                std::cout << "-----------------------------------------\n";
                for (int i = 0; i <= top; i++) {
                    std::cout << i << " | " << *(contacts[i]);
                }
                break;
            case Command::EXIT:
                for (int i = 0; i <= top; i++) {
                    delete contacts[i];
                }
                std::exit(0); 
                break; // delete persons
            case Command::NON : 
                std::cout << "No execution for command: " << input << std::endl; 
                break;
        }
    }
}

int main() {
    menu();
    return 0;
}