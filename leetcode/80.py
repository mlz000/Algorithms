class Solution(object):
    def removeDuplicates(self, nums):
        i = 0
        for x in nums:
            if i < 2 or x > nums[i - 2]:
                nums[i] = x
                i += 1
        return i