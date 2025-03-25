class MinStack:
    idx = -1
    values = [0]*30000
    mins = [0]*30000

    def __init__(self):
        pass

    def push(self, val: int) -> None:
        if self.idx == -1:
            self.mins[0] = val
        else:
            self.mins[self.idx+1] = min(self.getMin(), val)
        self.values[self.idx+1] = val
        self.idx += 1

    def pop(self) -> None:
        self.idx -= 1

    def top(self) -> int:
        return self.values[self.idx]

    def getMin(self) -> int:
        return self.mins[self.idx]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
