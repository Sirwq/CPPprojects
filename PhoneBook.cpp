#include <iostream>
#include <iomanip>
#include <cstring>

enum class Command {ADD, SEARCH, EXIT, NON};

class Person {
char name[10];
char lastname[20];
char login[20];
char adress[40];

public:

Person(const char* name, char* lastname, char* login, char* adress) {

    strncpy(this->name, name, sizeof(name) - 1);
    this->name[sizeof(name) - 1] = '\0';

    strncpy(this->lastname, lastname, sizeof(lastname) - 1);
    this->lastname[sizeof(lastname) - 1] = '\0';


    strncpy(this->login, login, sizeof(login) - 1);
    this->login[sizeof(login) - 1] = '\0';

    strncpy(this->adress, adress, sizeof(adress) - 1);
    this->adress[sizeof(adress) - 1] = '\0';

    }

    Person() {}

    static void createPers(Person& pers) {
        char name[10];
        char login[20];
        char adress[40];
        char lastname[20];

        std::cout << "Enter name: ";
        std::cin >> std::setw(10) >> name;
        std::cout << "Enter login: ";
        std::cin >> std::setw(20) >> login;
        std::cout << "Enter adress: ";
        std::cin >> std::setw(40) >> adress;
        std::cout << "Enter lastname: ";
        std::cin >> std::setw(20) >> lastname;


  
        strncpy(pers.name, name, sizeof(pers.name) - 1);
        pers.name[sizeof(name) - 1] = '\0';

        strncpy(pers.lastname, lastname, sizeof(pers.lastname) - 1);
        pers.lastname[sizeof(lastname) - 1] = '\0';


        strncpy(pers.login, login, sizeof(pers.login) - 1);
        pers.login[sizeof(login) - 1] = '\0';

        strncpy(pers.adress, adress, sizeof(pers.adress) - 1);
        pers.adress[sizeof(adress) - 1] = '\0';

    }

    friend std::ostream& operator<<(std::ostream& os, const Person& pers);
};


    std::ostream& operator<<(std::ostream& os, const Person& pers) {
        os << pers.name << " | " << pers.lastname 
        << " | " << pers.login << " | " << pers.adress << std::endl;
        return os;
    }


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