class Solution(object):
    def findLongestChain(self, a):
        a = sorted(a, key = lambda x : x[1])
        now = -1000000
        ans = 0
        for t in a:
            if now < t[0]:
                ans += 1
                now = t[1]
        return ans