class Solution(object):
    def productExceptSelf(self, a):
        n = len(a)
        ans = [1] * n
        for i in xrange(n):
            ans[i] = ans[i - 1] * a[i]
        now = 1
        for i in xrange(n - 1, -1, -1):
            ans[i] = ans[i - 1] * now
            if i == 0:
                ans[i] = now
            now *= a[i]
        return ans