class Solution(object):
    def hIndex(self, a):
        n = len(a)
        cnt = [0] * (n + 2) 
        for x in a: 
            if x > n:   cnt[n] += 1
            else:   cnt[x] += 1
        for x in xrange(n, -1, -1): 
            cnt[x] += cnt[x + 1]
            if cnt[x] >= x: return x