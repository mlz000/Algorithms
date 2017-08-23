class Solution(object):
    def countDigitOne(self, n):
        if n <= 0:  return 0
        now, t, ans = n, 1, 0
        while now > 0:
            x = now % 10
            now /= 10
            ans += now * t
            if x == 1:  ans += n % t + 1
            if x > 1:   ans += t
            t *= 10
        return ans