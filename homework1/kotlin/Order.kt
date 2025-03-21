class Order {
    private val items: MutableList<String> = mutableListOf() // 주문 항목들

    fun addItem(item: String) {
        // 주문 항목 추가
        items.add(item)
    }

    fun getItems(): List<String> {
        // 주문 항목 가져오기
        return items
    }
}