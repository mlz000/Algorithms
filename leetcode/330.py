class Solution(object):
    def minPatches(self, a, n):
        now, ans, i, l = 1, 0, 0, len(a)
        while now <= n:
            if i < l and a[i] <= now:
                now += a[i]
                i += 1
            else:
                ans += 1
                now += now
        return ans