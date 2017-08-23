class Solution(object):
    def maxProfit(self, a):
        n = len(a)
        h1, h2 = -100000000, -10000000
        ans1, ans2 = 0, 0
        for i in xrange(0, n):
            ans2 = max(ans2, h2 + a[i])
            h2 = max(h2, ans1 - a[i])
            ans1 = max(ans1, h1 + a[i])
            h1 = max(h1, -a[i])
        return ans2