class Solution(object):
    def findMin(self, a):
        n = len(a)
        l, r, ans = 0, n - 1, 2 ** 32
        while l <= r:
            m = l + r >> 1
            if a[l] <= a[m]:
                ans = min(ans, a[l])
                l = m + 1
            else:
                ans = min(ans, a[m])
                r = m - 1
        return ans