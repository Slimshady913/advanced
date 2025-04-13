#include <iostream>
#include <string>

// InternalClass
class InternalClass {
public:
    std::string fetch() {
        return "get user info";
    }
};

// ExternalClass
class ExternalClass {
public:
    std::string search() {
        return "get user info";
    }
};

// Adapter
class Adapter {
private:
    ExternalClass* external;
public:
    Adapter(ExternalClass* external) : external(external) {}

    std::string fetch() {
        return external->search();
    }
};

int main() {
    ExternalClass external;
    Adapter adapter(&external);

    std::cout << adapter.fetch() << std::endl;

    return 0;
}