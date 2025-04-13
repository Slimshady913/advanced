class Calculator {
    private var result: Double = 0.0

    fun add(value: Double): Calculator {
        result += value
        return this // Return itself
    }

    fun subtract(value: Double): Calculator {
        result -= value
        return this // Return itself
    }

    fun multiply(value: Double): Calculator {
        result *= value
        return this // Return itself
    }

    fun divide(value: Double): Calculator {
        if (value != 0.0) {
            result /= value
        }
        return this // Return itself
    }

    fun getResult(): Double {
        return result
    }
}

fun main() {
    val calc = Calculator()
    val result = calc.add(5.0)
        .multiply(2.0)
        .subtract(3.0)
        .divide(2.0)
        .getResult()
    println(result)
}