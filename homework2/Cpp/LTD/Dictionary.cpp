#include <iostream>
#include <map>
#include <string>

int main() {
    // std::map 선언
    std::map<std::string, int> wordCount;

    // 데이터 삽입
    wordCount["apple"] = 3;
    wordCount["banana"] = 5;
    wordCount["cherry"] = 2;

    // 데이터 출력
    std::cout << "Word counts:" << std::endl;
    for (const auto& pair : wordCount) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // 특정 키 검색
    std::string key = "banana";
    if (wordCount.find(key) != wordCount.end()) {
        std::cout << key << " is found with count: " << wordCount[key] << std::endl;
    } else {
        std::cout << key << " is not found." << std::endl;
    }

    // 데이터 삭제
    wordCount.erase("cherry");

    // 삭제 후 출력
    std::cout << "\nAfter deletion:" << std::endl;
    for (const auto& pair : wordCount) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}