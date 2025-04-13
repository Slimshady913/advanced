#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;
    std::string address;

    Person() : name(""), age(0), address("") {}
};

class PersonBuilder {
private:
    Person person;

public:
    PersonBuilder& with_name(const std::string& name) {
        person.name = name;
        return *this; // Return self
    }

    PersonBuilder& with_age(int age) {
        person.age = age;
        return *this; // Return self
    }

    PersonBuilder& with_address(const std::string& address) {
        person.address = address;
        return *this; // Return self
    }

    Person build() {
        return person;
    }
};

int main() {
    Person person = PersonBuilder()
                        .with_name("홍길동")
                        .with_age(20)
                        .with_address("양산시 부산대학로")
                        .build();

    std::cout << "Name: " << person.name << "\n";
    std::cout << "Age: " << person.age << "\n";
    std::cout << "Address: " << person.address << "\n";

    return 0;
}