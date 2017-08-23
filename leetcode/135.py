class Solution(object):
    def candy(self, a):
        n = len(a)
        x = [1] * n
        for i in xrange(n - 1):
            if a[i + 1] > a[i]:
                x[i + 1] = x[i] + 1
        for i in xrange(n - 1, 0, -1):
            if i == 0:
                break
            if a[i - 1] > a[i]:
                x[i - 1] = max(x[i - 1], x[i] + 1)
        return sum(x)