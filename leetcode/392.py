class Solution(object):
    def isSubsequence(self, s, t):
        if not t :
            if s:
                return False
            else:
                return True
        n, m = len(s), len(t)
        p = 0
        for i in xrange(n):
            while p < m and t[p] != s[i]:
                p += 1
            if p >= m:
                return False
            p += 1
        return True