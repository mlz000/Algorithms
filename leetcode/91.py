class Solution(object):
    def numDecodings(self, s):
        n = len(s)
        if n == 0:  return 0
        f = [0] * (n + 1)
        f[0] = 1
        for i in xrange(1, n + 1):
            if i == 1:  
                if s[i - 1] == '0': return 0
                f[i] = 1
                continue
            if s[i - 1] != '0': f[i] += f[i - 1]
            if i >= 2:
                x = int(s[i - 2] + s[i - 1])
                if x >= 1 and x <= 26 and s[i - 2] != '0':
                    f[i] += f[i - 2]
        return f[n]