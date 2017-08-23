class Solution(object):
    def leastBricks(self, a):
        h = {}
        n = len(a)
        for i in xrange(n):
            last = 0
            for x in a[i]:
                last += x
                h[last] = h.get(last, 0) + 1
            h[last] = 0
        return n - max(h[x] for x in h)