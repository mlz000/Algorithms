class Solution(object):
    def nextGreaterElement(self, n):
        s = str(n)
        for i in xrange(len(s) - 2, -1, -1):
            ans, t = 2 ** 31, list(s[i : ])
            l = len(t)
            for j in range(1, l):
                if t[j] > t[0]:
                    t2 = list(s[i : ])
                    now = t2.pop(j)
                    t2 = sorted(t2)
                    now = int(s[ : i] + now + ''.join(t2))
                    ans = min(ans, now)
            if ans != 2 ** 31:  return ans
        return -1