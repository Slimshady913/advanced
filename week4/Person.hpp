#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

using namespace std;

class Person {
    protected:
        string name;
        int age;
    public:
        Person(string _name, int _age);
        ~Person();
        void walk();
        void run();
};

#endif