class Person:
    num_people = 0

    def __init__(self, name):
        num_people += 1
        print(f"There are {Person.num_people} people in the world!")

    @staticmethod
    def achoo():
        print("Achoo!")

p1 = Person("Alice")
p2 = Person("Bob")
Person.achoo()
