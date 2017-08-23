class Solution(object):
    def numberOfArithmeticSlices(self, a):
        n = len(a)
        ans = [0, 0]
        for i in xrange(2, n):
            if a[i] - a[i - 1] == a[i - 1] - a[i - 2]:
                ans.append(ans[i - 1] + 1)
            else:
                ans.append(0)
        return sum(ans)