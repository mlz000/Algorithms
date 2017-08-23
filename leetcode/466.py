class Solution(object):
    def getMaxRepetitions(self, s1, n1, s2, n2):
        l1, l2 = len(s1), len(s2)
        dp = [[0] * 30 for i in xrange(l1 + 1)]
        for c in s2:
            if c not in s1:   return 0
        for i in xrange(l1):
            now, j = i, 0
            while j < l2:
                while s1[now % l1] != s2[j]:    now += 1
                now += 1
                j += 1
            dp[i][0] = now - i
        for k in xrange(1, 30):
            for i in xrange(l1):
                dp[i][k] = dp[i][k - 1] + dp[(i + dp[i][k - 1]) % l1][k - 1]
        now, cnt = 0, 0
        for k in xrange(29, -1, -1):
            if now + dp[now % l1][k] <= l1 * n1:
                cnt += (1 << k)
                now += dp[now % l1][k]
        return cnt / n2