class Solution(object):
    def rob(self, a):
        f = [0] * 2
        n = len(a)
        for i in xrange(n):
            f[0], f[1] = f[1], max(f[1], f[0] + a[i]) 
        return f[1]