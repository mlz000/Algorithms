class Solution(object):

    def __init__(self, nums):
        self.nums = nums

    def reset(self):
        return self.nums
        

    def shuffle(self):
        return random.sample(self.nums, len(self.nums)) 