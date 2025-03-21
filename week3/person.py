class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def __del__(self):
        print(f'{self.name}이(가) 소멸되었습니다.')

    def walk(self):
        print(f'{self.name}이(가) 걷는다.')

    def run(self):
        print(f'{self.name}이(가) 뜁니다.')

p = Person('철수', 20)
p.walk()
p.run()
del p
print('print 함수가 삭제되었습니다.')