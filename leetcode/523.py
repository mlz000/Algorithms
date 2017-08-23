class Solution(object):
    def checkSubarraySum(self, a, k):
        n = len(a) 
        k = abs(k)
        if k == 0:
            for i in range(0, n - 1):
                if a[i] == 0 and a[i + 1] == 0:
                    return True
            return False
        sum = [0] * (n + 1)
        for i in xrange(1, n + 1): 
            a[i - 1] %= k
            sum[i] = (sum[i - 1] + a[i - 1]) % k
        G = {}
        G[0] = 1
        for i in xrange(1, n + 1):
            if G.has_key(sum[i]):
                if i - G[sum[i]] >= 1:
                    return True
            else:
                G[sum[i]] = i
        return False