class Solution(object):
    def generate(self, n):
        a = []
        for i in range(n):
            a.append([0] * (i + 1))
            a[i][i] = a[i][0] = 1
            for j in range(1, i):
                a[i][j] = a[i - 1][j] + a[i - 1][j - 1]
        return a