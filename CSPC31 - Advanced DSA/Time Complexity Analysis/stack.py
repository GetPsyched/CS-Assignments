class stack(list):
    """Python implementation of a stack"""

    def __init__(self):
        super().__init__()

    def empty(self):
        return bool(self)

    def pop(self):
        self.pop()

    def push(self, elem):
        self.append(elem)

    def size(self):
        return len(self)

    def top(self):
        return self[-1]

def run_stack(n: int) -> int:
    s = stack()                   # 1
    for i in range(n):            # n * (4 + 3) + 2
        s.push(i)                 # b = 4

    return 7 * n + 3
