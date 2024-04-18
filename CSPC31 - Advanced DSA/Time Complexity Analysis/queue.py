class queue(list):
    """Python implementation of a queue"""

    def __init__(self):
        super().__init__()

    def back(self):
        return self[-1]

    def empty(self):
        return bool(self)

    def front(self):
        return self[0]

    def pop(self):
        self.pop()

    def push(self, elem):
        self.append(elem)

    def size(self):
        return len(self)

def run_queue(n: int) -> int:
    s = queue()                   # 1
    for i in range(n):            # n * (4 + 3) + 2
        s.push(i)                 # b = 4

    return 7 * n + 2
