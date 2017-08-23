class Solution(object):
    def findDiagonalOrder(self, a):
        n, m = len(a), len(a and a[0])
        return [a[i][j - i]
               for j in xrange(n + m - 1)
               for i in range(max(0, j - m + 1), min(j + 1, n))[::2 * (j % 2) - 1]]