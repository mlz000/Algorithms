class Solution(object):
    def rob(self, a):
        def gao(l, r, a):
            f = [0] * 2
            for i in xrange(l, r + 1):
                f[0], f[1] = f[1], max(f[1], f[0] + a[i])
            return f[1]
        n = len(a)
        if n == 0:  return 0
        elif n <= 2:    return max(a[0], a[n - 1])
        return max(gao(0, n - 2, a), gao(1, n - 1, a))