#include <iostream>

// 간단한 Fraction(분수) 클래스를 정의합니다.
class Fraction {
private:
    int numerator;   // 분자
    int denominator; // 분모

public:
    // 생성자
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (denominator == 0) {
            throw std::invalid_argument("분모는 0이 될 수 없습니다.");
        }
    }

    // + 연산자 오버로딩
    Fraction operator+(const Fraction& other) const {
        // 두 분수를 더할 때 공통 분모를 계산
        int newNumerator = numerator * other.denominator + other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    // - 연산자 오버로딩
    Fraction operator-(const Fraction& other) const {
        int newNumerator = numerator * other.denominator - other.numerator * denominator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    // * 연산자 오버로딩
    Fraction operator*(const Fraction& other) const {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    // / 연산자 오버로딩
    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("0으로 나눌 수 없습니다.");
        }
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        return Fraction(newNumerator, newDenominator);
    }

    // 출력 연산자 오버로딩 (std::ostream)
    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }
};

int main() {
    try {
        // Fraction 객체 생성
        Fraction f1(1, 2); // 1/2
        Fraction f2(3, 4); // 3/4
        Fraction f3(5, 6); // 5/6

        // Fraction 객체 출력
        std::cout << "Fraction 1 (f1): " << f1 << " (1/2)" << std::endl;
        std::cout << "Fraction 2 (f2): " << f2 << " (3/4)" << std::endl;
        std::cout << "Fraction 3 (f3): " << f3 << " (5/6)" << std::endl;

        // 사칙연산 테스트
        Fraction resultAdd = f1 + f2; // 덧셈
        Fraction resultSub = f1 - f2; // 뺄셈
        Fraction resultMul = f1 * f2; // 곱셈
        Fraction resultDiv = f1 / f2; // 나눗셈

        // 결과 출력
        std::cout << "덧셈 결과 (f1 + f2): " << f1 << " + " << f2 << " = " << resultAdd << std::endl;
        std::cout << "뺄셈 결과 (f1 - f2): " << f1 << " - " << f2 << " = " << resultSub << std::endl;
        std::cout << "곱셈 결과 (f1 * f2): " << f1 << " * " << f2 << " = " << resultMul << std::endl;
        std::cout << "나눗셈 결과 (f1 / f2): " << f1 << " / " << f2 << " = " << resultDiv << std::endl;

        // 추가 연산 테스트
        Fraction complexResult = (f1 + f2) * f3 - f2 / f1;
        std::cout << "복합 연산 결과 ((f1 + f2) * f3 - f2 / f1): "
                  << "((" << f1 << " + " << f2 << ") * " << f3 << ") - (" << f2 << " / " << f1 << ") = "
                  << complexResult << std::endl;

        // 예외 상황 테스트
        Fraction invalidFraction(1, 0); // 분모가 0인 경우
    } catch (const std::exception& e) {
        std::cerr << "오류 발생: " << e.what() << std::endl;
    }

    return 0;
}