class Solution(object):
    def maxRotateFunction(self, a):
        n = len(a)
        ans, now = 0, 0
        if n == 0:  return 0
        tot = sum(a)
        ans = now = sum([a[i] * i for i in xrange(n)])
        for i in xrange(n):
            print(ans, now)
            now += tot - n * a[n - 1 - i]
            ans = max(ans, now)
        return ans