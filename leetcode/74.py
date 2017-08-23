class Solution(object):
    def searchMatrix(self, a, target):
        n = len(a)
        if n == 0:  return False
        m = len(a[0])
        if m == 0:  return False
        l, r, ans = 0, n - 1, -1
        while l <= r:
            mid = (l + r) / 2
            if a[mid][0] > target:    r = mid - 1
            else:   l, ans = mid + 1, mid
        l, r, now = 0, m - 1, -1
        if ans == -1:   return False
        while l <= r:
            mid = (l + r) / 2
            if a[ans][mid] > target:    r = mid - 1
            else:   l, now = mid + 1, mid
        return a[ans][now] == target