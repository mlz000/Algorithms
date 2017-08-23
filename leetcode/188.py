class Solution(object):
    def maxProfit(self, k, a):
        n = len(a)
        ans = 0
        if k > n / 2:
            for i in range(0, n - 1):
                ans += max(a[i + 1] - a[i], 0)
            return ans
        s = [[0] * (k + 1) for i in range(n + 1)]
        b = [[0] * (k + 1) for i in range(n + 1)]
        if n < 2:
            return 0
        b[0][0] = -a[0]
        for i in range(1, n):
            b[i][0] = max(b[i - 1][0], -a[i])
        for i in range(k + 1):
            b[0][i] = -a[0]
        for i in range(1, n + 1):
            for j in range(1, k + 1):
                s[i][j] = max(s[i - 1][j], b[i - 1][j - 1] + a[i - 1])
                b[i][j] = max(b[i - 1][j], s[i - 1][j] - a[i - 1])
        return max(s[n][k], b[n][k])
        