fun main() {
    // 객체 생성
    val owner = RestaurantOwner()
    val restaurant = Restaurant()
    val cook = Cook("Chef", 3000f)
    val server = Server("Waiter", 2000f)
    val customer = Customer("Customer1", 100000f)

    // 식당에 종업원과 손님 추가
    restaurant.addWorker(cook)
    restaurant.addWorker(server)
    restaurant.addCustomer(customer)

    // 손님이 주문을 함
    val customerOrder = Order()
    customerOrder.addItem("Noodles")
    customerOrder.addItem("Sweet and Sour Pork")
    customer.placeOrder(customerOrder, server)

    // 서버가 요리사에게 요리를 요청함
    val preparedFood = server.requestFood(cook, customerOrder)

    // 서버가 손님에게 음식을 전달함
    server.deliverFood(preparedFood, customer)

    // 손님이 결제를 함
    customer.makePayment(server, 15000f)

    // 서버가 식당 주인에게 돈을 전달함
    server.transferMoney(owner, 15000f)

    // 식당 주인이 종업원들에게 월급을 지급함
    owner.paySalaries(listOf(cook, server))
}