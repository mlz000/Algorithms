class Solution(object):
    def permuteUnique(self, nums):
        ans = [[]]
        for x in nums:
            t = []
            for now in ans:
                for i in range(len(now) + 1):
                    t.append(now[ : i] + [x] + now[i :])
            print(t)
            ans = t
        return ans