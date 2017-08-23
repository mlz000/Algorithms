class Solution(object):
    def palindromePairs(self, s):
        n = len(s)
        ans, dict = [], {}
        for i in xrange(n): dict[s[i]] = i
        for i in xrange(n):
            l = len(s[i])
            for j in xrange(l + 1):
                s1, s2 = s[i][:j], s[i][j:]
                rs1, rs2 = s1[::-1], s2[::-1]
                if rs1 in dict and dict[rs1] != i and rs2 == s2:    ans.append([i, dict[rs1]])
                if j > 0 and rs2 in dict and dict[rs2] != i and rs1 == s1:    ans.append([dict[rs2], i])
        return ans