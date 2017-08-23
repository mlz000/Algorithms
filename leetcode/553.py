class Solution(object):
    def optimalDivision(self, nums):
        nums = map(str, nums)
        return len(nums) < 3 and '/'.join(nums) or nums[0] + '/(' + '/'.join(nums[1:]) + ')'