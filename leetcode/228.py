class Solution(object):
    def summaryRanges(self, a):
        s = []
        a.append(-100000)
        n = len(a)
        if n == 0:  return s
        l = r = a[0]
        for i in xrange(1, n):
            if a[i] == r + 1:   r += 1
            else:   
                if l != r:  s.append(str(l) + '->' + str(r))
                else:   s.append(str(l))
                l = r = a[i]
        return s