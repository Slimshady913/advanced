#include "Person.hpp"
#include "Student.hpp"

int main(){
    Person p1("Alice", 25);
    p1.walk();
    p1.run();
    
    Student s1("Bob", 20, "123456", "Computer Science");
    s1.walk(); 
    s1.run();
    s1.study();

    return 0;
}