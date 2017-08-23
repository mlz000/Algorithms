class Solution(object):
    def getHint(self, a, b):
        cnt1, cnt2 = [0] * 10, [0] * 10
        A, n, tot = 0, len(a), 0
        for i in xrange(n):
            if a[i] == b[i]:    A += 1
            cnt1[int(a[i])] += 1
            cnt2[int(b[i])] += 1
        for i in xrange(10):
            tot += min(cnt1[i], cnt2[i])
        return str(A) + 'A' + str(tot - A) + 'B'