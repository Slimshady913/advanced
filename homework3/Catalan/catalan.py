from functools import lru_cache

# 점화식을 사용하여 카탈란 수를 계산하는 람다 함수
catalan = lru_cache(None)(lambda n: 1 if n == 0 else sum(catalan(i) * catalan(n - 1 - i) for i in range(n)))

# 예제 사용법
if __name__ == "__main__":
    try:
        n = 8  # 다른 카탈란 수를 계산하려면 이 값을 변경하세요
        if n < 0:
            raise ValueError("Input must be a non-negative integer.")
        print(f"Catalan number C({n}) is {catalan(n)}")
    except ValueError as e:
        print(e)