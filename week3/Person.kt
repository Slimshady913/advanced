class Person(private val name: String, private val age: Int) {

    init {
        println("$name object has been created.")
    }

    fun walk() {
        println("$name is walking.")
    }

    fun run() {
        println("$name is running.")
    }

    protected fun finalize() {
        println("$name has been destroyed.")
    }
}

fun main() {
    var p: Person? = Person("Chulsoo", 20)
    p?.walk()
    p?.run()
    p = null
    System.gc() // Force Garbage Collection
    println("The print function has been deleted.")
}