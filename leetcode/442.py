class Solution(object):
    def findDuplicates(self, a):
        n = len(a)
        ans = []
        for i in xrange(n):
            if a[abs(a[i]) - 1] < 0:
                ans.append(abs(a[i]))
            else:
                a[abs(a[i]) - 1] *= -1
        return ans