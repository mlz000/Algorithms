class Solution(object):
    def palindromePairs(self, s):
        n = len(s)
        ans, dict = [], {}
        dict[s[0]] = 0
        for i in xrange(1, n):
            l = len(s[i])
            for j in xrange(l + 1):
                s1, s2 = s[i][0:j], s[i][j:]
        return ans