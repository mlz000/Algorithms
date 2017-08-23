class Solution(object):
    def findPoisonedDuration(self, a, b):
        last, ans, n = 0, 0, len(a)
        a.append(2 ** 32)
        for i in xrange(n):
            ed = a[i] + b - 1
            ans += min(ed, a[i + 1] - 1) - a[i] + 1
        return ans