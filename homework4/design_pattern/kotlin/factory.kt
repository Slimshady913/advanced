// Define the Animal interface
interface Animal {
    fun speak(): String
}

// Implement the Dog class
class Dog : Animal {
    override fun speak(): String {
        return "Woof!"
    }
}

// Implement the Cat class
class Cat : Animal {
    override fun speak(): String {
        return "Meow!"
    }
}

// Define the AnimalFactory class
class AnimalFactory {
    fun createAnimal(animalType: String): Animal? {
        return when (animalType.lowercase()) {
            "dog" -> Dog()
            "cat" -> Cat()
            else -> null
        }
    }
}

// Example usage
fun main() {
    val factory = AnimalFactory()

    val dog = factory.createAnimal("dog")
    println(dog?.speak()) // Output: Woof!

    val cat = factory.createAnimal("cat")
    println(cat?.speak()) // Output: Meow!
}