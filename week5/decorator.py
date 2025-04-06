def counter(func):
    cnt = 0
    def wrapper(*args, **kwargs):
        nonlocal cnt
        cnt += 1
        rtn = func(*args, **kwargs)
        print(f"{func.__name__} has been called {cnt} times, and the result is {rtn}")
        return rtn
    return wrapper

@counter
def add(a, b):
    return a + b

print(add(1, 2))
print(add(3, 4))
print(add(5, 6))