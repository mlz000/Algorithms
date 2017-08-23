class Solution(object):
    def sortColors(self, a):
        n = len(a)
        i, j, k = 0, 0, n - 1
        while j <= k:
            if a[j] == 0:
                a[i], a[j] = a[j], a[i]
                i += 1
                j += 1
            elif a[j] == 1:
                j += 1
            else:
                a[j], a[k] = a[k], a[j]
                k -= 1
        