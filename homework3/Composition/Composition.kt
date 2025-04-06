package Composition

// WalkMethod 인터페이스 정의
interface WalkMethod {
    fun walk(): Int
}

// WalkToSchool 클래스가 WalkMethod를 구현
class WalkToSchool(private val distance: Int) : WalkMethod {
    override fun walk(): Int {
        println("Walking to school, distance: $distance km")
        return distance
    }
}

// WalkHome 클래스가 WalkMethod를 구현
class WalkHome(private val distance: Int) : WalkMethod {
    override fun walk(): Int {
        println("Walking home, distance: $distance km")
        return distance
    }
}

// Person 클래스
class Person(private val name: String, private val walkMethod: WalkMethod) {
    fun walk() {
        println("$name is walking...")
        walkMethod.walk()
    }
}

// main 함수
fun main() {
    val john = Person("John", WalkToSchool(2)) // WalkToSchool 객체 전달
    john.walk()

    val jane = Person("Jane", WalkHome(3)) // WalkHome 객체 전달
    jane.walk()
}