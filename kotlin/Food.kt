class Food {
    private val items: MutableList<String> = mutableListOf() // 음식 항목들

    fun addItem(item: String) {
        // 음식 항목 추가
        items.add(item)
    }

    fun getItems(): List<String> {
        // 음식 항목 가져오기
        return items
    }
}