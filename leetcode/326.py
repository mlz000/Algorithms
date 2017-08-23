class Solution(object):
    def isPowerOfThree(self, n):
        if n == 0:
            return False
        while n:
            if n % 3 != 0 and n != 1:
                return False
            n /= 3
        return True