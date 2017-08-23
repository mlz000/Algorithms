class Solution(object):
    def findMaxLength(self, a):
        n = len(a)
        if n == 0:  return 0
        sum = [0] * n
        for i in xrange(n): 
            if a[i] == 0: a[i] = -1
            if i == 0: sum[i] = a[i]
            else: sum[i] = sum[i - 1] + a[i]
        ans, cnt = 0, {0 : -1}
        for i in xrange(n):
            if sum[i] in cnt:
                ans = max(i - cnt[sum[i]], ans)
            else:
                cnt[sum[i]] = i
        return ans