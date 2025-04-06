#include <iostream>
#include <memory>
#include <string>

class WalkMethod {
public:
    virtual ~WalkMethod() = default;
    virtual int walk() const = 0;
};

class WalkToSchool : public WalkMethod {
private:
    int distance;
public:
    WalkToSchool(int distance) : distance(distance) {}
    int walk() const override {
        std::cout << "Walking to school, distance: " << distance << " km" << std::endl;
        return distance;
    }
};

class WalkHome : public WalkMethod {
private:
    int distance;
public:
    WalkHome(int distance) : distance(distance) {}
    int walk() const override {
        std::cout << "Walking home, distance: " << distance << " km" << std::endl;
        return distance;
    }
};

class Person {
private:
    std::string name;
    std::shared_ptr<WalkMethod> walkMethod;
public:
    Person(const std::string& name, std::shared_ptr<WalkMethod> walkMethod)
        : name(name), walkMethod(walkMethod) {}

    void walk() const {
        std::cout << name << " is walking..." << std::endl;
        walkMethod->walk();
    }
};

int main() {
    std::shared_ptr<WalkMethod> walkToSchool = std::make_shared<WalkToSchool>(2);
    Person john("John", walkToSchool);
    john.walk();

    std::shared_ptr<WalkMethod> walkHome = std::make_shared<WalkHome>(3);
    Person jane("Jane", walkHome);
    jane.walk();

    return 0;
}