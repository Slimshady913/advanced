#include "Student.hpp"

#include <iostream>

using namespace std;

Student::Student(string _name, int _age, string _studentID, string _major) : Person(_name, _age) {
    studentID = _studentID;
    major = _major;
    cout << "Student " << name << " is created" << endl;
}

Student::~Student() {
    cout << "Student " << name << " is destroyed" << endl;
}

void Student::study() {
    cout << "Student " << name << " with student ID " << studentID << " is studying " << major << endl;
}