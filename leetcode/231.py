class Solution(object):
    def isPowerOfTwo(self, n):
        if n <= 0:
            return False
        while n:
            if n & 1 and n != 1:
                return False
            n >>= 1
        return True
        