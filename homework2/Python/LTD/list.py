# 파이썬 리스트 예제

# 리스트 생성
fruits = ["apple", "banana", "cherry"]
print("Original list:", fruits)

# 요소 접근
print("First fruit:", fruits[0])
print("Last fruit:", fruits[-1])

# 요소 수정
fruits[1] = "blueberry"
print("Modified list:", fruits)

# 요소 추가
fruits.append("orange")
print("List after addition:", fruits)

# 요소 삽입
fruits.insert(1, "kiwi")
print("List after inserting at index 1:", fruits)

# 요소 제거
fruits.remove("cherry")
print("List after removing 'cherry':", fruits)

# 요소 꺼내기
popped_fruit = fruits.pop()
print("Popped fruit:", popped_fruit)
print("List after popping:", fruits)

# 리스트 슬라이싱
print("Sliced list (first two):", fruits[:2])

# 리스트 반복
print("List iteration:")
for fruit in fruits:
    print(fruit)

# 리스트 내포
squared_numbers = [x**2 for x in range(5)]
print("List comprehension (squared numbers):", squared_numbers)