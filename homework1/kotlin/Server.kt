class Server(name: String, salary: Float) : Worker(name, salary) {
    fun takeOrder(customer: Customer): Order {
        // 주문 받기
        println("$name 이(가) ${customer.name} 의 주문을 받았습니다.")
        return customer.order
    }

    fun deliverFood(food: Food, customer: Customer) {
        // 음식 전달
        println("$name 이(가) ${customer.name} 에게 음식을 전달했습니다: ${food.getItems()}")
    }

    fun receivePayment(customer: Customer): Float {
        // 결제 받기
        val amount = customer.paymentAmount
        println("$name 이(가) ${customer.name} 에게서 $amount 원을 받았습니다.")
        return amount
    }

    fun requestFood(cook: Cook, order: Order): Food {
        // 요리 요청
        println("$name 이(가) ${cook.name} 에게 요리를 요청했습니다.")
        return cook.prepareFood(order)
    }

    fun transferMoney(owner: RestaurantOwner, amount: Float) {
        // 돈 전달
        owner.receiveMoney(amount)
        println("$name 이(가) 식당 주인에게 $amount 원을 전달했습니다.")
    }
}