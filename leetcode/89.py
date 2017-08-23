class Solution(object):
    def grayCode(self, n):
        ans = [0]
        for i in range(n):
            ans += [x + (1 << i) for x in reversed(ans)]
        return ans