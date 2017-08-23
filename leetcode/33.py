class Solution(object):
    def search(self, a, target):
        n = len(a)
        if n == 0:  return -1
        l, r = 0, n - 1
        while l <= r:
            m = (l + r) >> 1
            if a[m] == target:  return m
            if a[m] < target:
                if a[0] <= a[m] or (a[0] > a[m] and a[0] > target): l = m + 1
                else:   r = m - 1
            else: 
                if a[0] > a[m] or a[0] <= target: r = m - 1
                else:   l = m + 1
        return -1