// File: List.kt

fun main() {
    // 1. MutableList 생성
    val mutableList: MutableList<String> = mutableListOf("Apple", "Banana", "Cherry")

    // 2. MutableList 출력
    println("초기 리스트: $mutableList")

    // 3. 요소 추가
    mutableList.add("Date")
    println("요소 추가 후: $mutableList")

    // 4. 특정 위치에 요소 추가
    mutableList.add(1, "Blueberry")
    println("특정 위치에 요소 추가 후: $mutableList")

    // 5. 요소 수정
    mutableList[2] = "Blackberry"
    println("요소 수정 후: $mutableList")

    // 6. 요소 삭제
    mutableList.remove("Banana")
    println("요소 삭제 후: $mutableList")

    // 7. 특정 위치의 요소 삭제
    mutableList.removeAt(0)
    println("특정 위치의 요소 삭제 후: $mutableList")

    // 8. 리스트 크기 확인
    println("리스트 크기: ${mutableList.size}")

    // 9. 리스트 순회
    println("리스트 순회:")
    for (item in mutableList) {
        println(item)
    }

    // 10. 리스트 초기화
    mutableList.clear()
    println("리스트 초기화 후: $mutableList")
}