// 연산자 오버로딩을 활용한 사칙연산 예제
// 이 예제에서는 Fraction(분수) 클래스에 대해 +, -, *, / 연산자를 오버로딩합니다.

data class Fraction(val numerator: Int, val denominator: Int) {
    // 덧셈 연산자 오버로딩
    operator fun plus(other: Fraction): Fraction {
        // 분모를 통일한 후 분자끼리 더함
        val commonDenominator = denominator * other.denominator
        val newNumerator = numerator * other.denominator + other.numerator * denominator
        return Fraction(newNumerator, commonDenominator).simplify()
    }

    // 뺄셈 연산자 오버로딩
    operator fun minus(other: Fraction): Fraction {
        // 분모를 통일한 후 분자끼리 뺌
        val commonDenominator = denominator * other.denominator
        val newNumerator = numerator * other.denominator - other.numerator * denominator
        return Fraction(newNumerator, commonDenominator).simplify()
    }

    // 곱셈 연산자 오버로딩
    operator fun times(other: Fraction): Fraction {
        // 분자끼리 곱하고 분모끼리 곱함
        val newNumerator = numerator * other.numerator
        val newDenominator = denominator * other.denominator
        return Fraction(newNumerator, newDenominator).simplify()
    }

    // 나눗셈 연산자 오버로딩
    operator fun div(other: Fraction): Fraction {
        // 첫 번째 분수에 두 번째 분수의 역수를 곱함
        val newNumerator = numerator * other.denominator
        val newDenominator = denominator * other.numerator
        return Fraction(newNumerator, newDenominator).simplify()
    }

    // 분수를 간단히 만드는 함수
    private fun simplify(): Fraction {
        val gcd = gcd(numerator, denominator)
        return Fraction(numerator / gcd, denominator / gcd)
    }

    // 최대공약수를 구하는 함수
    private fun gcd(a: Int, b: Int): Int {
        return if (b == 0) a else gcd(b, a % b)
    }

    override fun toString(): String {
        return "$numerator/$denominator"
    }
}

fun main() {
    // Fraction 클래스의 연산자 오버로딩 테스트
    val fraction1 = Fraction(1, 2) // 1/2
    val fraction2 = Fraction(1, 3) // 1/3

    println("Testing Fraction Operations:")
    println("Fraction 1: $fraction1")
    println("Fraction 2: $fraction2")
    println()

    val additionResult = fraction1 + fraction2
    println("Addition:")
    println("$fraction1 + $fraction2 = $additionResult")
    println()

    val subtractionResult = fraction1 - fraction2
    println("Subtraction:")
    println("$fraction1 - $fraction2 = $subtractionResult")
    println()

    val multiplicationResult = fraction1 * fraction2
    println("Multiplication:")
    println("$fraction1 * $fraction2 = $multiplicationResult")
    println()

    val divisionResult = fraction1 / fraction2
    println("Division:")
    println("$fraction1 / $fraction2 = $divisionResult")
    println()
}