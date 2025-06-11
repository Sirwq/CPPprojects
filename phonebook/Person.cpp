#include "Person.hpp"

Person::Person() {}

Person::Person(const char* name, char* lastname, char* login, char* adress) {

    copyField(this->name, name, sizeof(this->name));
    copyField(this->lastname, lastname, sizeof(this->lastname));
    copyField(this->login, login, sizeof(this->login));
    copyField(this->adress, adress, sizeof(this->adress));
}

void Person::copyField(char* dest, const char* src, size_t size) {
    std::strncpy(dest, src, size - 1);
    dest[size - 1] = '\0';
}

void Person::inputField(const char* prompt, char* dest, size_t size) {
    std::cout << prompt << ": ";
    std::cin >> std::setw(size) >> dest;
    dest[size - 1] = '\0';
}

void Person::createPers(Person& pers) {
    char name[10];
    char login[20];
    char adress[40];
    char lastname[20];

    inputField("Enter name", pers.name, sizeof(pers.name));
    inputField("Enter login", pers.login, sizeof(pers.login));
    inputField("Enter adress", pers.adress, sizeof(pers.adress));
    inputField("Enter lastname", pers.lastname, sizeof(pers.lastname));
}

void Person::print(std::ostream& os) const {
    os << name << " | " << lastname << " | " << login << " | " << adress;
}


std::ostream& operator<<(std::ostream& os, const Person& pers) {
    pers.print(os);
    os << std::endl;
    return os;
}