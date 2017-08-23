class Solution(object):
    def hIndex(self, a):
        n = len(a)
        if n == 0:  return 0
        l, r, ans = 0, n - 1, 0
        while l <= r:
            m = l + r >> 1
            if n - m <= a[m]:
                ans = n - m
                r = m - 1
            else:
                l = m + 1
        return ans