#include "Person.hpp"

int main(){
    Person p1("Alice", 25);
    p1.walk();
    p1.run();
    Person p2("Bob", 30);
    p2.walk();
    p2.run();

    return 0;
}