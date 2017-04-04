class stack():
    def __init__(self):
        self.stack = []
        self.top = 0

    def push(self, x):
        self.stack.append(x)
        self.top += 1

    def pop(self):
        self.stack.pop(-1)
        self.top -= 1

