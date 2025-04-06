class WalkToSchool:
    def __init__(self, distance):
        self.distance = distance

    def walk(self):
        print(f"Walking to school, distance: {self.distance} km")
        return self.distance

class WalkHome:
    def __init__(self, distance):
        self.distance = distance

    def walk(self):
        print(f"Walking home, distance: {self.distance} km")
        return self.distance
    
class Person:
    def __init__(self, name, walk_method):
        self.name = name
        self.walk_method = walk_method
    
    def walk(self):
        print(f"{self.name} is walking...")
        self.walk_method.walk()

p = Person("John", WalkToSchool(2))
p.walk()

p = Person("Jane", WalkHome(3))
p.walk()

## 터미널 입력하면서 확인
## v = [1,2,3,4,5]
## dir(v) #메소드 목록
## V.__iter__() 이터레이터(현재 위치에서 어느걸 가르키는지) 반환
## dir(it)
## it.__next__() # 다음 요소를 반환
## it.__next__() # 다음 요소를 반환

## def a():
##    while True:
##         i = 0
##         while True:
##             i += 1
##             yield i
## a
## a() <- 제너레이터
## g = a()
## dir(g)

## for i, j in enumerate(g):
##    if i > 10:
##        break
##    print(j)
## exit()