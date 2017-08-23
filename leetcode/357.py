class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        a = [9, 9, 8, 7, 6, 5, 4, 3, 2, 1]
        ans, x = 1, 1
        for i in range(min(n, 10)):
            x *= a[i]
            ans += x
        return ans