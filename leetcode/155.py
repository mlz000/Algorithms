class MinStack(object):

    def __init__(self):
        self.a = []

    def push(self, x):
        t = self.getMin()
        if t == None:
            t = x
        else:
            t = min(t, x)
        self.a.append((x, t))
        
    def pop(self):
        self.a.pop()  

    def top(self):
        if len(self.a) > 0:
            return self.a[-1][0]
        else:
            return None
    def getMin(self):
        if len(self.a) > 0:
            return self.a[-1][1]
        else:
            return None