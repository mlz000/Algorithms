class Solution(object):
    def nthSuperUglyNumber(self, n, p):
        k = len(p)
        f, cnt = [2 ** 32] * (n + 1), [0] * 101
        f[0] = 1
        for i in xrange(1, n):
            for j in xrange(k):
                f[i] = min(f[i], f[cnt[j]] * p[j])
            for j in xrange(k):
                cnt[j] += 1 if (f[i] == f[cnt[j]] * p[j]) else 0
        return f[n - 1]