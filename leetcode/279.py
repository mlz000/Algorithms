class Solution(object):
    def numSquares(self, n):
        nn = n
        while nn % 4 == 0 and nn != 0:
            nn /= 4
        if nn % 8 == 7:  return 4
        t = int(n ** 0.5)
        if t * t == n:   return 1
        for i in xrange(1, t + 1):
            x = n - i * i
            if x < 0:    continue
            xx = int(x ** 0.5)
            if xx * xx == x: return 2
        return 3