class Solution(object):
    def isInterleave(self, s1, s2, s3):
        l1 = len(s1); l2 = len(s2); l3 = len(s3)
        if l1 + l2 != l3:
            return False
        if l1 == 0:
            return s2 == s3
        if l2 == 0:
            return s1 == s3
        dp = [[False] * (l2 + 1) for i in range(l1 + 1)]
        for i in range(0, l1 + 1):
            for j in range(0, l2 + 1):
                if i == 0 and j == 0:   dp[i][j] = True
                elif i == 0: dp[i][j] = dp[i][j - 1] and (s2[j - 1] == s3[j - 1])
                elif j == 0: dp[i][j] = dp[i - 1][j] and (s1[i - 1] == s3[i - 1])
                else: dp[i][j] = (dp[i][j - 1] and s2[j - 1] == s3[i + j - 1]) or (dp[i - 1][j] and s1[i - 1] == s3[i + j - 1])
        return dp[l1][l2]