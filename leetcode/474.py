class Solution(object):
    def findMaxForm(self, strs, m, n):   
        dp = [[0] * (n + 1) for _ in range(m + 1)] 
        def count(s):
            return sum(1 for c in s if c == '0'), sum(1 for c in s if c == '1')
        for a, b in [count(s) for s in strs]:
            for x in range(m, -1, -1):
                for y in range(n, -1, -1):
                    if x >= a and y >= b:
                        dp[x][y] = max(1 + dp[x - a][y - b], dp[x][y])     
        return dp[m][n]