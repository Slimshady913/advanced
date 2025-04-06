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
