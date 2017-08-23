class NumArray(object):
    def __init__(self, nums):
        self.n, self.a = len(nums), nums
        self.c = [0] * (self.n + 1)
        for i in xrange(self.n):
            self.add(i + 1, self.a[i])
    def add(self, i, x):
        while i <= self.n:
            self.c[i] += x 
            i += i & -i
    def ask(self, i):
        t = 0
        while i > 0:
            t += self.c[i]
            i -= i & -i
        return t
    def update(self, i, val):
        self.add(i + 1, val - self.a[i])
        self.a[i] = val
    def sumRange(self, i, j):
        return self.ask(j + 1) - self.ask(i)