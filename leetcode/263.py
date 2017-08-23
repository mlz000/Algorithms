class Solution(object):
    def isUgly(self, num):
        for x in [2, 3, 5]:
            while num > 0 and num % x == 0:
                num /= x
        return num == 1