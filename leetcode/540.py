class Solution(object):
    def singleNonDuplicate(self, a):
        ans = 0
        for x in a:
            ans ^= x
        return ans