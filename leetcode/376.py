class Solution(object):
    def wiggleMaxLength(self, a):
        n = len(a)
        if (n < 2): return n
        diffs = []
        for i in xrange(1, n):
            x = a[i] - a[i - 1]
            if (x != 0): diffs.append(x)
        if (not diffs): return 1   
        cnt = 1
        for i in range(1, len(diffs)):
            prod = diffs[i] * diffs[i - 1]
            if (prod < 0):  cnt += 1 
        return cnt + 1