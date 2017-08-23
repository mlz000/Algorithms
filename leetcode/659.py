class Solution(object):
    def isPossible(self, a):
        l, r = min(a), max(a)
        sum = [0] * (r - l + 2)
        for x in a:
            sum[x - l] += 1
        r -= l
        i = 0
        while i <= r:
            if sum[i] == 0:
                i += 1
                continue
            len = 1
            for j in xrange(i + 1, r + 1):
                if sum[j] >= sum[j - 1]:
                    len += 1
                else:
                    break
            if len < 3:
                return False
            for j in xrange(i, i + len):
                sum[j] -= 1
        return True