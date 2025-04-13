#include <iostream>
#include <string>

class CPU {
public:
    std::string process() {
        return "CPU 처리 중";
    }
};

class Memory {
public:
    std::string load() {
        return "메모리 로딩 중";
    }
};

class SSD {
public:
    std::string read() {
        return "SSD 드라이브 읽는 중";
    }
};

// 파사드 클래스
class Computer {
private:
    CPU cpu;
    Memory memory;
    SSD ssd;

public:
    void boot() {
        std::cout << ssd.read() << std::endl;
        std::cout << memory.load() << std::endl;
        std::cout << cpu.process() << std::endl;
    }
};

int main() {
    Computer c;
    c.boot();
    return 0;
}