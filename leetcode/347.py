import collections

class Solution(object):
    def topKFrequent(self, nums, k):
        return zip(*collections.Counter(nums).most_common(k))[0]