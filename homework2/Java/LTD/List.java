import java.util.ArrayList;

public class List {
    public static void main(String[] args) {
        // 1. ArrayList 선언 및 초기화
        ArrayList<String> fruits = new ArrayList<>();

        // 2. 요소 추가
        fruits.add("Apple");
        fruits.add("Banana");
        fruits.add("Cherry");
        System.out.println("Initial List: " + fruits);

        // 3. 특정 위치에 요소 추가
        fruits.add(1, "Blueberry");
        System.out.println("After adding Blueberry at index 1: " + fruits);

        // 4. 요소 접근
        String firstFruit = fruits.get(0);
        System.out.println("First fruit: " + firstFruit);

        // 5. 요소 수정
        fruits.set(2, "Blackberry");
        System.out.println("After modifying index 2: " + fruits);

        // 6. 요소 제거
        fruits.remove("Banana"); // 값으로 제거
        System.out.println("After removing Banana: " + fruits);
        fruits.remove(1); // 인덱스로 제거
        System.out.println("After removing element at index 1: " + fruits);

        // 7. 리스트 크기 확인
        int size = fruits.size();
        System.out.println("Size of the list: " + size);

        // 8. 리스트 순회
        System.out.println("Iterating over the list:");
        for (String fruit : fruits) {
            System.out.println(fruit);
        }

        // 9. 리스트 비우기
        fruits.clear();
        System.out.println("After clearing the list: " + fruits);

        // 10. 리스트가 비어있는지 확인
        boolean isEmpty = fruits.isEmpty();
        System.out.println("Is the list empty? " + isEmpty);
    }
}