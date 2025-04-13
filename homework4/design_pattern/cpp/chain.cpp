#include <iostream>

class Calculator {
private:
    double result;

public:
    Calculator() : result(0) {}

    Calculator& add(double value) {
        result += value;
        return *this; // Return the current object
    }

    Calculator& subtract(double value) {
        result -= value;
        return *this; // Return the current object
    }

    Calculator& multiply(double value) {
        result *= value;
        return *this; // Return the current object
    }

    Calculator& divide(double value) {
        if (value != 0) {
            result /= value;
        } else {
            std::cerr << "Error: Division by zero!" << std::endl;
        }
        return *this; // Return the current object
    }

    double getResult() const {
        return result;
    }
};

int main() {
    Calculator calc;
    double result = calc.add(5)
                        .multiply(2)
                        .subtract(3)
                        .divide(2)
                        .getResult();
    std::cout << result << std::endl;
    return 0;
}