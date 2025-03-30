package LTD

fun main() {
    // 불변 리스트 생성
    val immutableList = listOf("Apple", "Banana", "Cherry")
    println("Immutable List: $immutableList")

    // 불변 리스트의 요소 접근
    println("First Element: ${immutableList[0]}") // 첫 번째 요소 접근
    println("Second Element: ${immutableList[1]}") // 두 번째 요소 접근

    // 불변 리스트의 반복문 사용
    println("Iterating through Immutable List:")
    for (item in immutableList) {
        println(item) // 각 요소 출력
    }

    // 불변 리스트는 수정이 불가능하므로 요소 추가, 삭제, 변경 등의 작업은 불가능
    // 예: immutableList.add("NewElement") // 컴파일 에러 발생
}
