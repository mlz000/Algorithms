class Solution(object):
    def totalHammingDistance(self, a):
        ans = 0
        for i in xrange(32):
            c1, c2 = 0, 0
            for x in a:
                if x >> i & 1:
                    c1 += 1
                else:
                    c2 += 1
            ans += c1 * c2
        return ans