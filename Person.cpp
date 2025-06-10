#include "Person.hpp"

Person::Person() {}

Person::Person(const char* name, char* lastname, char* login, char* adress) {

    strncpy(this->name, name, sizeof(name) - 1);
    this->name[sizeof(name) - 1] = '\0';

    strncpy(this->lastname, lastname, sizeof(lastname) - 1);
    this->lastname[sizeof(lastname) - 1] = '\0';


    strncpy(this->login, login, sizeof(login) - 1);
    this->login[sizeof(login) - 1] = '\0';

    strncpy(this->adress, adress, sizeof(adress) - 1);
    this->adress[sizeof(adress) - 1] = '\0';

}

void Person::createPers(Person& pers) {
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

void Person::print(std::ostream& os) const {
    os << name << " | " << lastname << " | " << login << " | " << adress;
}


std::ostream& operator<<(std::ostream& os, const Person& pers) {
    pers.print(os);
    os << std::endl;
    return os;
}