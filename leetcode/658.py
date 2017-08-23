class Solution(object):
    def findClosestElements(self, arr, k, x):
        a = sorted((abs(x - t), t) for t in arr)
        ans = sorted(map(lambda x : x[1], a[0 : k]))
        return ans