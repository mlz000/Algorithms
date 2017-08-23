class Solution(object):
    def trap(self, a):
        n = len(a)
        if n <= 1:  return 0
        h = [100000] * n
        h[0], h[n - 1] = a[0], a[n - 1]
        ans = 0
        for i in xrange(1, n - 1):
            now = max(a[i], h[i - 1])
            if h[i] > now:
                h[i] = now
        for i in xrange(n - 2, 0, -1):
            now = max(a[i], h[i + 1])
            if h[i] > now:
                h[i] = now
        ans = sum(h[i] - a[i] for i in xrange(n))
        return ans
