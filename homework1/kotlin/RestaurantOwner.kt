class RestaurantOwner {
    private var assets: Float = 0.0f // 자산

    fun receiveMoney(amount: Float) {
        // 돈 받기
        assets += amount
        println("식당 주인이 $amount 원을 받았습니다. 현재 자산: $assets")
    }

    fun paySalaries(workers: List<Worker>) {
        // 종업원들에게 월급 지급
        for (worker in workers) {
            worker.receiveSalary(worker.salary)
            assets -= worker.salary
        }
        println("모든 종업원들에게 월급을 지급했습니다. 남은 자산: $assets")
    }
}