#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Person.hpp"

#include <string>

using namespace std;

class Student : public Person {
protected:
    string studentID;
    string major;
public:
    Student(string _name, int _age, string _studentID, string _major);
    ~Student();
    void study();  
};

#endif