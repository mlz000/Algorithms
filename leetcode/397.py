class Solution(object):
    def integerReplacement(self, n):
        ans = 0
        while n != 1:
            print(n)
            if n % 2 == 0:  
                n >>= 1
                ans += 1
            elif n & 3 == 1 or n == 3:
                n = n - 1
                ans += 1
            else:
                n = n + 1
                ans += 1
        return ans