# dictionary 선언
word_count = {
    "apple": 3,
    "banana": 5,
    "cherry": 2
}

# 데이터 출력
print("Word counts:")
for key, value in word_count.items():
    print(f"{key}: {value}")

# 특정 키 검색
key = "banana"
if key in word_count:
    print(f"{key} is found with count: {word_count[key]}")
else:
    print(f"{key} is not found.")

# 데이터 삭제
word_count.pop("cherry", None)

# 삭제 후 출력
print("\nAfter deletion:")
for key, value in word_count.items():
    print(f"{key}: {value}")