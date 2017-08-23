class Solution(object):
    def singleNumber(self, a):
        n, bit = len(a), [0] * 33
        for x in a:
            x += 2 ** 31
            for i in xrange(33):
                bit[i] += (x >> i & 1) 
                bit[i] %= 3
        x = 0
        for i in xrange(33):
            if bit[i] > 0:
                x |= 1 << i
        return x - 2 ** 31