class Solution(object):
    def subarraySum(self, a, k):
        n = len(a)
        sum = [0] * n
        for i in xrange(n):
            sum[i] = sum[i - 1] + a[i]
        ans = 0
        d = {0 : 1}
        for i in xrange(n):
            ans += d.get(sum[i] - k, 0)
            d[sum[i]] = d.get(sum[i], 0) + 1
        return ans