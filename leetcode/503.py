class Solution(object):
    def nextGreaterElements(self, a):
        s, ans = [], [-1] * len(a)
        for i in range(len(a)) * 2:
            while s and a[s[-1]] < a[i]:
                ans[s.pop()] = a[i]
            s.append(i)
        return ans