class Solution(object):
    def maximumGap(self, a):
        n = len(a)
        if n < 2:   return 0
        mx, mn = max(a), min(a)
        if mn == mx: return 0
        sz = (mx - mn) // (n - 1) or 1
        b = [[2**31 - 1, -1] for i in xrange(0, (mx - mn) // sz + 1)]
        for x in a:
            id = (x - mn) // sz
            b[id][0] = min(b[id][0], x)
            b[id][1] = max(b[id][1], x)
        ans, last = 0, b[0][1]
        for i in xrange(1, len(b)):
            if b[i][0] == 2**31 - 1:    continue
            ans = max(ans, b[i][0] - last)
            last = b[i][1]
        return ans