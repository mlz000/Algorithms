class Solution(object):
    def findMinArrowShots(self, a):
        a = sorted(a, key = lambda x : (x[0], x[1]))
        last, ans = -2 ** 32, 0
        for i in xrange(len(a)):
            if a[i][0] > last:
                ans += 1
                last = a[i][1]
            elif a[i][1] < last:
                last = a[i][1]
        return ans