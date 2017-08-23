class Solution(object):
    def myPow(self, x, n):
        sgn = ans = 1
        if n < 0:
            sgn, n = -1, -n
        while n > 0:
            if n & 1:
                ans = ans * x
            x = x * x
            n >>= 1
        if sgn == -1:   ans = 1.0 / ans;
        return ans