class Solution(object):
    def countBits(self, n):
        ans = [0] * (n + 1)
        for i in xrange(1, n + 1):
            ans[i] = ans[i & (i - 1)] + 1
        return ans