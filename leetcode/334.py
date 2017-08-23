class Solution(object):
    def increasingTriplet(self, nums):
        mn, mn2 = 2 ** 32, 2 ** 32
        for n in nums:
            if n <= mn:
                mn = n
            elif n <= mn2:
                mn2 = n
            else:
                return True
        return False