class Solution(object):
    def searchMatrix(self, a, target):
        if len(a) == 0: return False
        n, m = len(a), len(a[0])
        i, j = 0, m - 1
        while i < n and j >= 0:
            if a[i][j] == target:   return True
            if target < a[i][j]:    j -= 1
            else:   i += 1
        return False