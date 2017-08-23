#
class Solution(object):
    def jump(self, a):
        st, ed, ans, n = 0, 0, 0, len(a)
        while ed < n - 1:
            ans += 1
            mx = 0
            for i in xrange(st, ed + 1):    mx = max(mx, i + a[i])
            if mx >= n - 1:  return ans
            st, ed = ed + 1, mx
            print(st, ed)
        return ans
