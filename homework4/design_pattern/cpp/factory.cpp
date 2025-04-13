#include <iostream>
#include <memory>
#include <string>

// Abstract base class
class Animal {
public:
    virtual ~Animal() = default;
    virtual std::string speak() const = 0;
};

// Derived class Dog
class Dog : public Animal {
public:
    std::string speak() const override {
        return "Woof!";
    }
};

// Derived class Cat
class Cat : public Animal {
public:
    std::string speak() const override {
        return "Meow!";
    }
};

// Factory class
class AnimalFactory {
public:
    std::unique_ptr<Animal> createAnimal(const std::string& animalType) {
        if (animalType == "dog") {
            return std::make_unique<Dog>();
        } else if (animalType == "cat") {
            return std::make_unique<Cat>();
        } else {
            return nullptr;
        }
    }
};

// Example usage
int main() {
    AnimalFactory factory;

    auto dog = factory.createAnimal("dog");
    if (dog) {
        std::cout << "Dog says: " << dog->speak() << std::endl;
    }

    auto cat = factory.createAnimal("cat");
    if (cat) {
        std::cout << "Cat says: " << cat->speak() << std::endl;
    }

    return 0;
}