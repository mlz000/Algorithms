class Solution(object):
    def firstMissingPositive(self, a):
        n = len(a)
        if n == 0:  return 1
        for i in xrange(n):
            while a[i] > 0 and a[i] <= n and a[a[i] - 1] != a[i]:
                a[a[i] - 1], a[i] = a[i], a[a[i] - 1]
        for i in xrange(n):
            if a[i] != i + 1:
                return i + 1
        return n + 1