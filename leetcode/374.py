class Solution(object):
    def guessNumber(self, n):
        l, r = 1, n
        while l <= r:
            m = (l + r) / 2
            t = guess(m)
            if t == 0:
                return m
            if t > 0:
                l = m + 1
            if t < 0:
                r = m - 1
        return None
        