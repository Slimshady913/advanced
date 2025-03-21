abstract class Worker(val name: String, val salary: Float) {
    open fun receiveSalary(amount: Float) {
        // 월급 받기
        println("$name 이(가) $amount 원의 월급을 받았습니다.")
    }
}