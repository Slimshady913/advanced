#f = lambda x: x + 1
# print(f(5))  # 

from collections import defaultdict

dt = defaultdict(lambda: 0)  # 기본값을 0으로 설정

dt[3] = 5
dt[8] = 10

for i in range(1, 10):
    print(dt[i])

print(dt)