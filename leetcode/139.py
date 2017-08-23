class Solution(object):
    def wordBreak(self, s, dict):
        n, m, G = len(s), len(dict), {}
        f = [False] * (n + 1)
        f[0] = True
        for ss in dict: G[ss] = 1
        for i in xrange(1, n + 1):
            for j in xrange(0, i):
                if f[j] and s[j : i] in G:  
                    f[i] = True
                    break
        return f[n]