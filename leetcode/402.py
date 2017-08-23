class Solution(object):
    def removeKdigits(self, s, k):
        a, n = [], len(s)
        for i in xrange(0, n):
            while k and a and s[i] < a[-1]:
                a.pop()
                k -= 1
            a.append(s[i])
        return ''.join(a[:-k or None]).lstrip('0') or '0'