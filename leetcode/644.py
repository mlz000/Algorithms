from collections import deque
class Solution(object):
    def findMaxAverage(self, a, k):
        def gao(i, j, k):
            return (sum[k] - sum[j]) * (j - i) > (sum[j] - sum[i]) * (k - j)
        n = len(a)
        sum = [0] * (n + 1)
        for i in xrange(1, n + 1):
            sum[i] = sum[i - 1] + a[i - 1]
        dq = deque()
        dq.append(0)
        ans = -1000000
        for i in xrange(k, n + 1):
            j = i - k + 1
            while len(dq) > 1 and gao(dq[0], dq[1], i):
                dq.popleft()
            while len(dq) > 1 and not gao(dq[-2], dq[-1], j):
                dq.pop()
            dq.append(j)
            ans = max(ans, 1.0 * (sum[i] - sum[dq[0]]) / (i - dq[0]))
        return ans