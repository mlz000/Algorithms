class Solution(object):
    def search(self, a, target):
        n = len(a)
        l, r = 0, n - 1
        while l <= r:
            m = (l + r) >> 1
            if a[m] == target:  return True
            if a[m] < a[r]:
                if a[m] < target <= a[r]:
                    l = m + 1
                else:   r = m - 1
            elif a[m] > a[r]:
                if a[l] <= target < a[m]:
                    r = m - 1
                else:   l = m + 1
            else:   r -= 1
        return False