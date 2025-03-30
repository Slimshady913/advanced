
class MyList:
    def __init__(self, data):
        self.data = data

    def __getitem__(self, index):
        return self.data[index]
    
    def __add__(self, other):
        added_data = []
        for i, j in zip(self.data, other.data):
            added_data.append(i+j)
        return MyList(added_data)
    
    def __str__(self):
        return f"MyList({self.data})"

ml1 = MyList([1,2,3,4,5])
ml2 = MyList([4,3,4,5,8])

print(ml1)
print(ml2)

print(ml1[2])
print(ml2[3])
print(ml1 + ml2)