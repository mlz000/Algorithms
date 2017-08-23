class Solution(object):
    def findMinMoves(self, a):
        n, tot = len(a), sum(a)
        if tot % n != 0:    return -1
        need = tot / n
        ans, now = 0, 0
        for i in xrange(n):
            now += a[i] - need
            ans = max(ans, abs(now), a[i] - need)
        return ans