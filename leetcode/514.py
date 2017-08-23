class Solution(object):
    def findRotateSteps(self, a, b):
        n, m = len(a), len(b)
        dp = [[0] * n for i in xrange(m + 1)]
        dis = [[0] * n for i in xrange(n)]
        for j in xrange(n):
            for k in xrange(n):
                dis[j][k] = min(abs(j - k), n - abs(j - k))
        mp = collections.defaultdict(list)
        for i, c in enumerate(a):   mp[c].append(i)
        for i in xrange(m - 1, -1, -1):
            for j in xrange(0, n):
                dp[i][j] = 100000
                for k in mp[b[i]]:
                    dp[i][j] = min(dp[i][j], dp[i + 1][k] + dis[j][k])
        return dp[0][0] + m