class Vector:
    # 벡터 클래스 초기화
    def __init__(self, x, y):
        self.x = x
        self.y = y

    # 덧셈 연산자 오버로딩
    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y)

    # 뺄셈 연산자 오버로딩
    def __sub__(self, other):
        return Vector(self.x - other.x, self.y - other.y)

    # 곱셈 연산자 오버로딩 (스칼라 곱)
    def __mul__(self, scalar):
        return Vector(self.x * scalar, self.y * scalar)

    # 나눗셈 연산자 오버로딩 (스칼라 나눗셈)
    def __truediv__(self, scalar):
        return Vector(self.x / scalar, self.y / scalar)

    # 객체 출력 형식 지정
    def __repr__(self):
        return f"Vector({self.x}, {self.y})"


# 연산자 오버로딩 테스트
if __name__ == "__main__":
    v1 = Vector(2, 3)
    v2 = Vector(4, 5)

    # 덧셈
    result_add = v1 + v2
    print(f"벡터 {v1}와 벡터 {v2}의 덧셈 결과: {result_add}")  # Vector(6, 8)

    # 뺄셈
    result_sub = v1 - v2
    print(f"벡터 {v1}와 벡터 {v2}의 뺄셈 결과: {result_sub}")  # Vector(-2, -2)

    # 스칼라 곱
    scalar = 3
    result_mul = v1 * scalar
    print(f"벡터 {v1}에 스칼라 {scalar}를 곱한 결과: {result_mul}")  # Vector(6, 9)

    # 스칼라 나눗셈
    scalar = 2
    result_div = v2 / scalar
    print(f"벡터 {v2}를 스칼라 {scalar}로 나눈 결과: {result_div}")  # Vector(2.0, 2.5)