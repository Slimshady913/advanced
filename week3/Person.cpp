#include <iostream>
#include <string>

using namespace std;

#include "Person.hpp"

Person::Person(string _name, int _age) {
    name = _name;
    age = _age;
    cout << "Person " << name << " is created" << endl;

}

Person::~Person() {
    cout << "Person " << name << " is destroyed" << endl;
}

void Person::walk() {
    cout << "Person " << name << " is walking" << endl;
}

void Person::run() {
    cout << "Person " << name << " is running" << endl;
}