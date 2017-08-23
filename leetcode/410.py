class Solution(object):
    def splitArray(self, a, m):
        l, r, ans, n = 1, 10**18, 10**18, len(a)
        for x in a: l = max(l, x)
        while l <= r:
            mid = (l + r) / 2
            sum, now = a[0], 1
            for i in xrange(1, n):
                if sum + a[i] <= mid: sum += a[i]
                else:
                    sum = a[i]
                    now += 1
            if now <= m:    
                r = mid - 1
                ans = mid
            else: l = mid + 1
        return ans