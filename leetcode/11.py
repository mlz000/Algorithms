class Solution(object):
    def maxArea(self, h):
        n = len(h)
        l, r, ans = 0, n - 1, 0
        while l < r:
            t = min(h[l], h[r])
            ans = max(ans, (r - l) * t)
            while h[l] <= t and l < r:   l += 1
            while h[r] <= t and l < r:   r -= 1
        return ans