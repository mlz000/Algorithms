class Solution(object):
    def divide(self, a, b):
        x, y, ans = abs(a), abs(b), 0
        sgn = 1 if a * b > 0 else -1
        while x >= y:
            now, cnt = y, 1
            while now * 2 < x:
                now <<= 1
                cnt <<= 1
            ans += cnt
            x -= now
        ans *= sgn
        ans = min(ans, 2 ** 31 - 1)
        return ans