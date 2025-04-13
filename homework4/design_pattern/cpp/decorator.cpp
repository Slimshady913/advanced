#include <iostream>
#include <memory>

// Base class
class Coffee {
public:
    virtual ~Coffee() = default;
    virtual int cost() const {
        return 5;
    }
};

// Decorator base class
class CoffeeDecorator : public Coffee {
protected:
    std::shared_ptr<Coffee> coffee;
public:
    CoffeeDecorator(std::shared_ptr<Coffee> coffee) : coffee(std::move(coffee)) {}
    int cost() const override {
        return coffee->cost();
    }
};

// Milk decorator
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(std::move(coffee)) {}
    int cost() const override {
        return coffee->cost() + 2;
    }
};

// Sugar decorator
class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(std::move(coffee)) {}
    int cost() const override {
        return coffee->cost() + 1;
    }
};

int main() {
    std::shared_ptr<Coffee> coffee = std::make_shared<Coffee>();
    std::cout << "Plain coffee cost: " << coffee->cost() << std::endl;

    std::shared_ptr<Coffee> coffeeWithMilk = std::make_shared<MilkDecorator>(coffee);
    std::cout << "Coffee with milk cost: " << coffeeWithMilk->cost() << std::endl;

    std::shared_ptr<Coffee> coffeeWithSugar = std::make_shared<SugarDecorator>(coffee);
    std::cout << "Coffee with sugar cost: " << coffeeWithSugar->cost() << std::endl;

    std::shared_ptr<Coffee> coffeeWithMilkAndSugar = std::make_shared<SugarDecorator>(coffeeWithMilk);
    std::cout << "Coffee with milk and sugar cost: " << coffeeWithMilkAndSugar->cost() << std::endl;

    return 0;
}