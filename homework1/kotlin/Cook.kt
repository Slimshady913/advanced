class Cook(name: String, salary: Float) : Worker(name, salary) {
    fun prepareFood(order: Order): Food {
        // 요리 준비
        val food = Food()
        for (item in order.getItems()) {
            food.addItem(item)
        }
        println("$name 이(가) 요리를 준비했습니다: ${food.getItems()}")
        return food
    }
}