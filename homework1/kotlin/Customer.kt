class Customer(val name: String, var money: Float) {
    var order: Order = Order() // 주문
    var paymentAmount: Float = 0.0f // 결제 금액

    fun placeOrder(order: Order, server: Server) {
        // 주문하기
        this.order = order
        println("$name 이(가) ${server.name} 에게 주문을 했습니다.")
    }

    fun makePayment(server: Server, amount: Float) {
        // 결제하기
        if (money >= amount) {
            money -= amount
            paymentAmount = amount
            println("$name 이(가) ${server.name} 에게 $amount 원을 결제했습니다. 남은 소지금: $money")
        } else {
            println("$name 이(가) $amount 원을 결제할 충분한 돈이 없습니다.")
        }
    }
}