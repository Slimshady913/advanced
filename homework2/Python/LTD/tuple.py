# Python 튜플 사용 예제

# 튜플 생성
empty_tuple = ()  # 빈 튜플
single_element_tuple = (42,)  # 단일 요소 튜플 (콤마 필요)
multiple_elements_tuple = (1, 2, 3, 4, 5)  # 여러 요소를 가진 튜플

# 튜플 요소 접근
print("First element:", multiple_elements_tuple[0])
print("Last element:", multiple_elements_tuple[-1])

# 튜플 언패킹
a, b, c = (10, 20, 30)
print("Unpacked values:", a, b, c)

# 중첩 튜플
nested_tuple = ((1, 2), (3, 4), (5, 6))
print("Nested tuple:", nested_tuple)

# 튜플의 불변성
try:
    multiple_elements_tuple[0] = 100  # 오류 발생
except TypeError as e:
    print("Error:", e)

# 딕셔너리에서 키로 튜플 사용
tuple_key_dict = {('x', 'y'): "Point A", ('a', 'b'): "Point B"}
print("Value for key ('x', 'y'):", tuple_key_dict[('x', 'y')])

# 튜플 메서드
example_tuple = (1, 2, 3, 2, 4, 2)
print("Count of 2:", example_tuple.count(2))
print("Index of 3:", example_tuple.index(3))