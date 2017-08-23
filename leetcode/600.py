class Solution(object):
    def findIntegers(self, n):
        def dfs(pos, last, eq, n, a):
            if pos == n:
                return 1
            if not eq and dp[pos][last] != -1:
                return dp[pos][last]
            t = 0
            lim = a[pos] + 1 if eq else 2
            for i in xrange(lim):
                if i & last != 1:
                    t += dfs(pos + 1, i, eq and i == a[pos], n, a)
            if not eq:
                dp[pos][last] = t
            return t
        a = []
        while n > 0:
            a.append(n & 1)
            n >>= 1
        a.reverse()
        dp = [[-1] * 2 for i in xrange(len(a))]
        return dfs(0, 0, True, len(a), a)