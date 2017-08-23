class Solution(object):
    def singleNumber(self, a):
        t, ans = 0, [0] * 2
        for x in a:
            t ^= x
        for x in a:
            if x & (t & -t):
                ans[0] ^= x
            else:
                ans[1] ^= x
        return ans