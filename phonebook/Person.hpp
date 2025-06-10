#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <iomanip>
#include <cstring>

class Person {
    char name[10];
    char lastname[20];
    char login[20];
    char adress[40];
public:
    Person();
    Person(const char* name, char* lastname, char* login, char* adress);

    static void inputField(const char* prompt, char* dest, size_t size);
    void print(std::ostream& os) const;
    static void createPers(Person& pers);
};

std::ostream& operator<<(std::ostream& os, const Person& pers);

#endif