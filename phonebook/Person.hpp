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
    void copyField(char* dest, const char* src, size_t size);
public:
    Person();
    Person(const char* name, char* lastname, char* login, char* adress);
    
    static void inputField(const char* prompt, char* dest, size_t size);
    void print(std::ostream& os) const;
    static void createPers(Person& pers);

    const char* getName() const { return name; }
    const char* getLastname() const { return lastname; }
    const char* getLogin() const { return login; }
    const char* getAdress() const { return adress; }
};

std::ostream& operator<<(std::ostream& os, const Person& pers);

#endif