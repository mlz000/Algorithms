class Solution(object):
    def threeSumClosest(self, a, target):
        n = len(a)
        a = sorted(a)
        ans = 2 ** 30
        for i in xrange(n - 2):
            j, k = i + 1, n - 1
            while j < k:
                now = a[i] + a[j] + a[k]
                if now == target:   return now
                ans = now if abs(now - target) < abs(ans - target) else ans
                if now > target:
                    k -= 1
                else:
                    j += 1
        return ans