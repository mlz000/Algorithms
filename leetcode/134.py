class Solution(object):
    def canCompleteCircuit(self, a, b):
        n, c = len(a), [0] * len(a) * 2
        for i in xrange(0, 2 * n - 1):  c[i] = a[i % n] - b[i % n]
        now, l = 0, 0
        for i in xrange(0, 2 * n - 1):
            if now + c[i] < 0:
                now, l = 0, 0
            else:
                now += c[i]
                l += 1
                print(l)
                if l == n:
                    return (i - l + 1) % n
        return -1