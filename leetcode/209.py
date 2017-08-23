class Solution(object):
    def minSubArrayLen(self, s, a):
        n = len(a)
        if n == 0:  return 0
        sum, ans, last = 0, 2 ** 30, 0
        a.append(0)
        for i in xrange(n):
            sum += a[i]
            while sum >= s:
                print(last, i)
                ans = min(ans, i - last + 1)
                sum -= a[last]
                last += 1
        if ans == 2 ** 30:  ans = 0
        return ans