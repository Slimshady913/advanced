fun main() {
    // Map 생성
    val dictionary = mapOf(
        "apple" to "달고 아삭한 과일",
        "book" to "묶여 있는 글이나 인쇄된 페이지 모음",
        "computer" to "데이터 저장 및 처리를 위한 전자 장치"
    )
    println("기본 Dictionary가 생성되었습니다: $dictionary")

    // Map에서 값 접근
    println("\nDictionary에서 특정 키의 값을 가져옵니다:")
    println("'apple'의 정의: ${dictionary["apple"]}")
    println("'book'의 정의: ${dictionary["book"]}")

    // Map 순회
    println("\nDictionary의 모든 항목을 순회합니다:")
    for ((key, value) in dictionary) {
        println("$key: $value")
    }

    // Mutable Map 예제
    val mutableDictionary = mutableMapOf(
        "pen" to "잉크로 글씨를 쓰거나 그림을 그리는 도구",
        "table" to "평평한 상판이 있는 가구"
    )
    println("\nMutable Dictionary가 생성되었습니다: $mutableDictionary")

    // 새 항목 추가
    println("\nMutable Dictionary에 새 항목을 추가합니다: 'chair' -> '앉기 위한 가구'")
    mutableDictionary["chair"] = "앉기 위한 가구"
    println("추가 후 Mutable Dictionary: $mutableDictionary")

    // 항목 제거
    println("\nMutable Dictionary에서 항목을 제거합니다: 'pen'")
    mutableDictionary.remove("pen")
    println("제거 후 Mutable Dictionary: $mutableDictionary")

    // 업데이트된 Map 출력
    println("\n업데이트된 Mutable Dictionary의 모든 항목을 출력합니다:")
    for ((key, value) in mutableDictionary) {
        println("$key: $value")
    }
}