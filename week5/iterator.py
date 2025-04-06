class DataLoader:
    def __init__(self, file_paths):
        self.file_paths = file_paths
        self.index = 0

    def __iter__(self):
        return self
    
    def load_data(self, file_path):
        return {"data": "sample_data", "file_path": file_path}

    def __next__(self):
        if self.index < len(self.file_paths):
            result = self.load_data(self.file_paths[self.index])
            self.index += 1
            return result
        else:
            raise StopIteration

dl = DataLoader(["file1.txt", "file2.txt", "file3.txt"])
for data in dl:
    print(data)