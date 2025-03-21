class Restaurant {
    private val workers: MutableList<Worker> = mutableListOf() // 종업원 목록
    private val customers: MutableList<Customer> = mutableListOf() // 손님 목록

    fun addCustomer(customer: Customer) {
        // 손님 추가
        customers.add(customer)
    }

    fun addWorker(worker: Worker) {
        // 종업원 추가
        workers.add(worker)
    }
}