class Solution(object):
    def isScramble(self, s1, s2):
        l1, l2 = len(s1), len(s2)
        if l1 != l2:    return False
        if l1 == 0: return True
        dp = [[[False] * (l1 + 1) for j in xrange(0, l1 + 1)] for i in xrange(0, l1 + 1)]
        for L in xrange(0, l1):
            for i in xrange(0, l1 - L):
                for j in xrange(0, l1 - L):
                    if L == 0:
                        dp[L][i][j] = True if s1[i] == s2[j] else False
                    else:
                        for k in xrange(0, L):
                            dp[L][i][j] = dp[L][i][j] or (dp[k][i][j] and dp[L - k - 1][i + k + 1][j + k + 1])
                            dp[L][i][j] = dp[L][i][j] or (dp[k][i][j + L - k] and dp[L - k - 1][i + k + 1][j])
                            if dp[L][i][j] == True: break
        return dp[l1 - 1][0][0]