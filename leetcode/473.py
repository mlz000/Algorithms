class Solution(object):
    def makesquare(self, a):
        tot = sum(a)
        if tot % 4 != 0 or len(a) == 0:    return False
        n, avg, v = len(a), tot / 4, []
        ans = [False] * (1 << n)
        for mask in xrange(1 << n):
            now = 0
            for j in xrange(n):
                if mask >> j & 1:
                   now += a[j]
            if now == avg:
                for k in v:
                    if k & mask == 0:
                        t = k | mask
                        ans[t] = True
                        if ans[((1 << n) - 1) ^ t]: return True
                v.append(mask)
        return False