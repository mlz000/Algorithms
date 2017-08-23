class Solution(object):
    def rangeBitwiseAnd(self, l, r):
        i = 0
        while l != r:
            r >>= 1
            l >>= 1
            i += 1
        return l << i