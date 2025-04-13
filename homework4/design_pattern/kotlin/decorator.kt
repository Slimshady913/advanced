open class Coffee {
    open fun cost(): Int {
        return 5
    }
}

open class CoffeeDecorator(private val coffee: Coffee) : Coffee() {
    override fun cost(): Int {
        return coffee.cost()
    }
}

class MilkDecorator(coffee: Coffee) : CoffeeDecorator(coffee) {
    override fun cost(): Int {
        return super.cost() + 2
    }
}

class SugarDecorator(coffee: Coffee) : CoffeeDecorator(coffee) {
    override fun cost(): Int {
        return super.cost() + 1
    }
}

fun main() {
    val coffee = Coffee()
    println(coffee.cost()) // 5

    val coffeeWithMilk = MilkDecorator(coffee)
    println(coffeeWithMilk.cost()) // 7

    val coffeeWithSugar = SugarDecorator(coffee)
    println(coffeeWithSugar.cost()) // 6

    val coffeeWithMilkAndSugar = SugarDecorator(coffeeWithMilk)
    println(coffeeWithMilkAndSugar.cost()) // 8
}